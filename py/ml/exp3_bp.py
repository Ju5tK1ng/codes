import numpy as np
import matplotlib.pyplot as plt
import math
import random
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

def BP_standard(x_train, y_train, learning_rate):
    # ------- 在（0，1）范围内随机初始化网络中所有连接权和阈值 --------
    d = len(x_train[0])  # 输入层神经元个数 = 训练集输入的列数
    q = d + 1  # 隐藏层神经元个数 = 输入层神经元个数 + 1
    l = len(y_train[0])  # 输出层神经元个数 = 训练集输出的列数
    gamma = [random.random() for i in range(q)]  # 隐藏层的阈值
    theta = [random.random() for i in range(l)]  # 输出层的阈值
    v = [[random.random() for i in range(q)] for j in range(d)]  # 输入层到隐藏层的连接权矩阵 d * q
    w = [[random.random() for i in range(l)] for j in range(q)]  # 隐藏层到输出层的连接权矩阵 q * l

    # ------- 循环迭代 训练BP网络中的参数 --------
    count = 0  # 迭代次数
    E = 0
    losslist = []   # 误差列表
    while True:
        count += 1
        elist = []
        for k in range(len(x_train)):
            # 根据当前参数和式（5.3）计算当前样本的输出yk
            alpha = np.dot(x_train[k], v)   # np.dot(1 * d, d * q) = 1 * q
            b = sigmoid(alpha - gamma, 1)   # 1 * q
            beta = np.dot(b, w)             # np.dot(1 * q, q * l) = 1 * l
            yk = sigmoid(beta - theta, 1)   # 预测的y值 1 * l
            # 在该样本上的均分误差
            E = sum((yk - y_train[k]) * (yk - y_train[k])) / 2
            elist.append(E)
            # 根据式（5.10）计算输出层神经元的梯度项gj
            g = yk * (1 - yk) * (y_train[k] - yk)   # 1 * l
            e = b * (1 - b) * np.dot(w, g.T).T      # 1 * q
            # 根据式（5.11）- （5.14）更新连接权
            w += learning_rate * np.dot(b.reshape(q, 1), g.reshape(1, l))   # np.dot(q * 1, 1 * l) = q * l
            theta += -learning_rate * g
            v += learning_rate * np.dot(x_train[k].reshape(d, 1), e.reshape(1, q))  # np.dot(d * 1, 1 * q) = d * q
            gamma += -learning_rate * e
        losslist.append(np.mean(elist))
        # 停止条件
        if np.abs(E) < 0.0001 or count > 1000:
            break
    # Loss可视化
    plt.figure()
    plt.plot([i + 1 for i in range(count)], losslist)
    plt.legend(['standard BP'])
    plt.xlabel('iteration')
    plt.ylabel('loss')
    plt.show()
    return w, theta, v, gamma, count

def sigmoid(x, dimension):
    if dimension == 1:
        for i in range(len(x)):
            x[i] = 1 / (1 + math.exp(-x[i]))
    else:
        for i in range(len(x)):
            x[i] = sigmoid(x[i], dimension - 1)
    return x

def output(x, w, theta, v, gamma):
    alpha = np.dot(x, v)        # np.dot(1 * d, d * q) = 1 * q
    b = sigmoid(alpha - gamma, 1)   # 使用已经训练好的隐藏层阈值gamma
    beta = np.dot(b, w)         # np.dot(1 * q, q * l) = 1 * l
    y = sigmoid(beta - theta, 1)    # 使用已经训练好的输出层阈值theta
    return y

def Edist(a, b):
    dist = 0
    for i in range(len(a)):
        dist += (np.square(a[i] - b[i]))
    return np.sqrt(dist)

if __name__ == '__main__':
    # ------------- 数据导入与处理 -------------
    # 导入鸢尾花数据集
    iris = load_iris()
    X = iris.data
    label = iris.target
    scaler = StandardScaler()
    scaler.fit(X)
    cnt_label = len(np.unique(label))
    # 将标签转化为向量
    Y = []
    label_vec = [[0 for i in range(cnt_label)] for j in range(cnt_label)]
    for i in range(cnt_label):
        label_vec[i][i] = 1
    for i in range(len(label)):
        Y.append(label_vec[label[i]])
    Y = np.array(Y)
    # 划分训练集和测试集
    x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

    # ------------- BP训练 -------------
    print("开始训练BP神经网络......")
    w, theta, v, gamma, count = BP_standard(x_train, y_train, 0.2)
    theta = (np.sum(theta, axis=0))/len(x_train)
    gamma = (np.sum(gamma, axis=0))/len(x_train)
    print("训练结束!")
    print("迭代次数为：", count)

    # ------------- BP测试 -------------
    testNum = x_test.shape[0]
    print("开始测试......")
    print("测试样本有", testNum, "个")
    rightCount = 0
    for i in range(testNum):
        predict_vec = output(x_test[i], w, theta, v, gamma)
        # 初始化
        dist = 999999
        result_vec = label_vec[0]
        # 遍历所有可能的标签，找出距离最小的作为预测的向量
        for vec in label_vec:
            if(len(predict_vec) != len(vec)):
                print("Error ", predict_vec, vec)
            temp_dist = Edist(predict_vec, vec)
            if temp_dist < dist:
                dist = temp_dist
                result_vec = vec
        if list(result_vec) == list(y_test[i]):
            rightCount += 1
    accuracy = rightCount / testNum
    print("准确率为：", accuracy)