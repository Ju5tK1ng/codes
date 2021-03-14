import numpy as np
import pandas as pd

from numpy import linalg # 线性模型使用linalg

# 训练集和验证集路径
trainPath = 'C:/Users/wj/Desktop/machineLearning/data/xiguaexcel.xls'
# testPath = 'C:/Users/25355/Desktop/logistic-regression-hw-master/data/test.csv'
# 训练集和验证集数据
trainData = pd.read_excel(trainPath)
# testData = pd.read_excel(testPath)

# length表示数据条数
length = len(list(trainData['density']))
# pd.read_excel读出的数据是元组，使用list将其转换成数组
x = np.array([list(trainData['density']), list(trainData['sugar']), np.ones(17)])

y = np.array(list(trainData['good']))

# beta = [w;b] = [w1;w2;b]
beta = np.array([[0],[0],[1]])

last_iota_beta = 0
# n,记录迭代次数
n = 0


while 1:
    # 计算当前ι(β)的大小
    beta_T_X = np.dot(beta.T[0], x) # β转置后只有一排
    this_iota_beta = 0
    for i in range(length):
        this_iota_beta += (-y[i]*beta_T_X[i] + np.log(1 + np.exp(beta_T_X[i])))

    # 终止条件，当前后两次ι(β)的差的绝对值小于一定的值，就认为函数收敛了，此时得到ι(β)的最优解
    if np.abs(this_iota_beta - last_iota_beta) <= 0.000001:
        break

    # 牛顿法，更新β
    n = n + 1
    last_iota_beta = this_iota_beta
    # 关于β的一次求导和二次求导
    dbeta = 0
    d2beta = 0
    for i in range(length):
        dbeta -= np.dot(np.array([x[:, i]]).T, (y[i] - (np.exp(beta_T_X[i]) / (1 + np.exp(beta_T_X[i])))))
        d2beta += np.dot(np.array([x[:, i]]).T, np.array([x[:, i]]).T.T) * (
                    np.exp(beta_T_X[i]) / (1 + np.exp(beta_T_X[i]))) * (
                             1 - (np.exp(beta_T_X[i]) / (1 + np.exp(beta_T_X[i]))))
    beta = beta - np.dot(linalg.inv(d2beta), dbeta) # 使用inv求矩阵的逆

