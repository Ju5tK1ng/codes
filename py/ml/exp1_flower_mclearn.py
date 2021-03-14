import numpy as np
import pandas as pd
from sklearn import preprocessing

#bigfloat.exp(5000,bigfloat.precision(100))

from numpy import linalg # 线性模型使用linalg

# 使用LabelEncoder将文本属性转化为数值
def transformAttribute(label, data):
    le = preprocessing.LabelEncoder()
    le = le.fit(label)
    data = le.transform(data)

    return data

# 输入测试集，并将机器判定结果打印在控制台
def machineJudge(data, beta, label):
    lengthOfTest = len(data[0])
    # widthOfTest是属性的个数+1
    width = len(data)
    # result存储计算结果
    result = np.zeros(lengthOfTest)
    answer = np.zeros(lengthOfTest, dtype='i')
    for i in range(lengthOfTest):
        result[i] = 1 / (1 + np.exp(-(np.dot(beta.T[0], data[:, i]))))
        if result[i] < 0.5:
            answer[i] = 0
        else:
            answer[i] = 1
    le = preprocessing.LabelEncoder()
    le = le.fit(label)

    print('计算结果:', result)
    return le.inverse_transform(answer)

# 对数几率回归算法，x为样本空间，y为标记空间，length为样本条数，width为（属性个数+1）
def logisticRegression(x, y, length, width):
    # beta = [w;b] = [w1;w2;b]
    beta = np.zeros((width, 1))
    beta[width - 1][0] = 1

    last_iota_beta = 0
    # n,记录迭代次数
    n = 0

    while 1:

        # 计算当前ι(β)的大小
        beta_T_X = np.dot(beta.T[0], x)  # β转置后只有一排
        this_iota_beta = 0
        for i in range(length):
            this_iota_beta += (-y[i] * beta_T_X[i] + np.log(1 + np.exp(beta_T_X[i])))

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
        beta = beta - np.dot(linalg.inv(d2beta), dbeta)  # 使用inv求矩阵的逆
    print(beta.T)
    print('迭代次数:', n)
    return beta

if __name__ == '__main__':
    # 西瓜数据集2.0
    # 训练集和测试集路径
    trainPath = 'C:/Users/wj/Desktop/machineLearning/data/flower_train.csv'
    testPath = 'C:/Users/wj/Desktop/machineLearning/data/flower_test.csv'
    # 训练集和测试集数据
    trainData = pd.read_csv(trainPath)
    testData = pd.read_csv(testPath)

    # length表示数据条数, lengthOfTest是测试集的条数
    length = len(list(trainData['sepal_length']))
    lengthOfTest = len(list(testData['sepal_length']))
    # pd.read_excel读出的数据是元组，使用list将其转换成数组

    x = np.array([list(trainData['sepal_length']), list(trainData['sepal_width']),
                  list(trainData['petal_length']), list(trainData['petal_width']),
                  np.ones(length)])

    test = np.array([list(testData['sepal_length']), list(testData['sepal_width']),
                  list(testData['petal_length']), list(testData['petal_width']),
                  np.ones(lengthOfTest)])
    # width表示属性种类数量+1
    width = len(x)
    preY = list(trainData['species'])
    for i in range(len(preY)):
        if ((preY[i] == 'virginica') or (preY[i] == 'versicolor')):
            preY[i] = 'others'
    firstY = np.array(transformAttribute(['setosa', 'others'], preY))
    secondY = np.array(transformAttribute(['versicolor', 'virginica'], list(trainData['species'])[45:]))

    testOfy = np.array(list(testData['species']))

    print((x[:, 0]).T)
    beta1 = logisticRegression(x, firstY, length, width)
    beta2 = logisticRegression(x[:,45:], secondY, length-45, width)

    print('x：', x)
    print('firstY：', firstY)

    print('beta1参数取值：', beta1.T[0])
    print('beta2参数取值：', beta2.T[0])
    judge1 = machineJudge(test, beta1, ['setosa', 'others'])
    judge2 = machineJudge(test[:, 5:], beta2, ['versicolor', 'virginica'])
    print('第一次机器分类：', judge1)
    print('第二次机器分类：', judge2)
    L = 0
    for i in range(len(judge1)):
        if judge1[i] == 'others':
            break
        L = i
    print(type(judge1))
    result = np.append(judge1[:L+1], judge2)
    error = 0
    for i in range(len(testOfy)):
        if testOfy[i] != result[i]:
            i = i + 1
    print('最终机器分类：', )
    print('真实判定：', testOfy)
    print("正确率：", 1 - (error / len(testOfy)))