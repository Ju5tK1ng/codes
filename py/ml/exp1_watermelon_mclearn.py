import numpy as np
import pandas as pd
from sklearn import preprocessing

from numpy import linalg # 线性模型使用linalg

# 使用LabelEncoder将文本属性转化为数值
def transformAttribute(label, data):
    le = preprocessing.LabelEncoder()
    le = le.fit(label)
    data = le.transform(data)

    return data

# 输入测试集，并将机器判定结果打印在控制台
def machineJudge(data, beta):
    lengthOfTest = len(data[0])
    # widthOfTest是属性的个数+1
    width = len(data)
    # result存储计算结果
    result = np.zeros(lengthOfTest)
    answer = np.zeros(lengthOfTest, dtype='i')
    for i in range(lengthOfTest):
        result[i] = 1 / (1 + np.exp(-(np.dot((data[:, i]).T, beta))))
        if result[i] < 0.5:
            answer[i] = 0
        else:
            answer[i] = 1
    le = preprocessing.LabelEncoder()
    le = le.fit(['是', '否'])

    # print('计算结果:', result)
    # print('机器判定:', le.inverse_transform(answer))
    return answer

# 对数几率回归算法，x为样本空间，y为标记空间，length为样本条数，width为（属性个数+1）
def logisticRegression(x, y, length, width):
    # beta = [w;b] = [w1;w2;b]
    beta = np.zeros((width, 1))
    beta[width - 1][0] = 0

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

from sklearn.model_selection import train_test_split

if __name__ == '__main__':
    # 西瓜数据集2.0
    # 数据路径
    path = 'C:/Users/wj/Desktop/machineLearning/data/watermelon2.xlsx'
    # 数据
    data = pd.read_excel(path)

    # length表示数据条数
    length = len(list(data['编号']))

    # pd.read_excel读出的数据是元组，使用list将其转换成数组
    x = np.array([transformAttribute(['浅白', '青绿', '乌黑'], list(data['色泽'])),
                  transformAttribute(['蜷缩', '稍蜷', '硬挺'], list(data['根蒂'])),
                  transformAttribute(['沉闷', '浊响', '清脆'], list(data['敲声'])),
                  transformAttribute(['模糊', '稍糊', '清晰'], list(data['纹理'])),
                  transformAttribute(['凹陷', '稍凹', '平坦'], list(data['脐部'])),
                  transformAttribute(['软粘', '硬滑'], list(data['触感'])),
                  np.ones(length)], dtype='i')
    y = np.array(transformAttribute(['是', '否'], list(data['好瓜'])), dtype='i')

    # width表示属性种类数量+1
    width = len(x)

    print("x: ", x)
    print("y: ", y)
    y_T = y.reshape(len(y), 1)

    print(x.T)
    print(y_T)
    x_train, x_test, y_train, y_test = train_test_split(x.T, y_T, test_size = 0.25, random_state=13)

    print(y_train)

    y_train_T = y_train.reshape(1, len(y_train))[0]

    print(x_train.T)
    print(y_train_T)
    beta = logisticRegression(x_train.T, y_train_T, len(x_train), width)

    print('参数取值：', beta.T[0])
    answer = machineJudge(x_test.T, beta)
    real = y_test.reshape(1, len(y_test))[0]
    print('真实判定：', real)
    print('机器判定:', answer)
    error = 0
    for i in range(len(answer)):
        if answer[i] != real[i]:
            error = error + 1
    print("准确率：", 1 - (error/len(answer)))

