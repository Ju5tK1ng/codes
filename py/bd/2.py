from sklearn.datasets import load_iris
from sklearn import decomposition
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import numpy as np
import math
import copy

# macos中文显示
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']


# 五数概括
def five_num_sum(nums):
    # 先给数组从小到大排序
    nums = sorted(nums)
    length = len(nums)

    # 最小值
    minNum = nums[0]
    # 最大值
    maxNum = nums[length - 1]

    # Q1，中位数，Q3
    median_index = int(length / 2)
    Q1_index = int((length + 1) / 4)
    Q3_index = int(3 * (length + 1) / 4)
    if length % 2 == 0:
        median = (nums[median_index] + nums[median_index + 1]) / 2
    else:
        median = nums[int(length / 2)]
    Q1 = nums[Q1_index]
    Q3 = nums[Q3_index]

    return minNum, Q1, median, Q3, maxNum


# 所有属性的条形图绘制
def drawBar(iris):
    # 组数 m = 1.87*(n-1)^0.4
    m = int(1.87 * math.pow(149, 0.4))
    print("组数为：", m)

    # 绘制条形图像
    data1 = sorted(iris['SpealLength'])
    data2 = sorted(iris['SpealWidth'])
    data3 = sorted(iris['PetalLength'])
    data4 = sorted(iris['PetalWidth'])

    # 组间隔
    interval1 = (data1[len(data1) - 1] - data1[0]) / m
    interval2 = (data2[len(data2) - 1] - data2[0]) / m
    interval3 = (data3[len(data3) - 1] - data3[0]) / m
    interval4 = (data4[len(data4) - 1] - data4[0]) / m

    # 横坐标数值
    x_index1 = [data1[0] + i * interval1 for i in range(m + 1)]
    x_index2 = [data2[0] + i * interval2 for i in range(m + 1)]
    x_index3 = [data3[0] + i * interval3 for i in range(m + 1)]
    x_index4 = [data4[0] + i * interval4 for i in range(m + 1)]

    plt.subplot(2, 2, 1)
    plt.hist(iris['SpealLength'], x_index1, color='green')
    plt.xlabel('花萼长度值')
    plt.ylabel('频数')
    plt.title("花萼长度分布图")

    plt.subplot(2, 2, 2)
    plt.hist(iris['SpealWidth'], x_index2, color='green')
    plt.xlabel('花萼宽度值')
    plt.ylabel('频数')
    plt.title("花萼宽度分布图")

    plt.subplot(2, 2, 3)
    plt.hist(iris['PetalLength'], x_index3, color='green')
    plt.xlabel('花瓣长度值')
    plt.ylabel('频数')
    plt.title("花瓣长度分布图")

    plt.subplot(2, 2, 4)
    plt.hist(iris['PetalWidth'], x_index4, color='green')
    plt.xlabel('花瓣宽度值')
    plt.ylabel('频数')
    plt.title("花瓣宽度分布图")

    plt.show()


# 单个属性不同类别的条形图绘制：
def drawSingleBar(data):
    # 组数 m = 1.87*(n-1)^0.4
    m = int(1.87 * math.pow(49, 0.4))
    print("组数为：", m)

    # 绘制条形图像
    data1 = sorted(data[0:50])
    data2 = sorted(data[50:100])
    data3 = sorted(data[100:150])

    # 组间隔
    interval1 = (data1[len(data1) - 1] - data1[0]) / m
    interval2 = (data2[len(data2) - 1] - data2[0]) / m
    interval3 = (data3[len(data3) - 1] - data3[0]) / m

    # 横坐标数值
    x_index1 = [data1[0] + i * interval1 for i in range(m + 1)]
    x_index2 = [data2[0] + i * interval2 for i in range(m + 1)]
    x_index3 = [data3[0] + i * interval3 for i in range(m + 1)]

    plt.subplot(1, 3, 1)
    plt.hist(data[0:50], x_index1, color='deepskyblue')
    plt.xlabel('Setosa花萼长度值')
    plt.ylabel('频数')
    plt.title("Setosa")

    plt.subplot(1, 3, 2)
    plt.hist(data[50:100], x_index2, color='pink')
    plt.xlabel('Versicolor花萼长度值')
    plt.ylabel('频数')
    plt.title("Versicolor")

    plt.subplot(1, 3, 3)
    plt.hist(data[100:150], x_index3, color='orange')
    plt.xlabel('Virginica花萼长度值')
    plt.ylabel('频数')
    plt.title("Virginica")

    plt.show()


# 盒图绘制
def drawBox(iris):
    plt.boxplot(iris, flierprops={'marker': 'x'}, labels=iris.columns, showmeans=True)

    plt.title("iris data box")
    plt.show()


# 单个属性不同类别盒图绘制
def drawSingleBox(data):
    print(data)

    df = pd.DataFrame({'Setosa': list(data[0:50]), 'Versicolor': list(data[50:100]), 'Virginica': list(data[100:150])})
    print(df)
    plt.boxplot(df, flierprops={'marker': 'x'}, labels=df.columns, showmeans=True)

    plt.title("三种鸢尾花花萼长度盒图")
    plt.show()


# 两两散点图绘制
def drawScatter(iris):
    # 计算相关系数和协方差
    coef = np.corrcoef(iris.T)
    cov = np.cov(iris.T)
    print("------------相关系数矩阵-------------")
    print(coef)
    print("------------协方差矩阵-------------")
    print(cov)

    attributes = iris.columns
    pos = 1
    for i in range(len(attributes)):
        for j in range(i+1, len(attributes)):
            plt.subplot(2, 3, pos)
            plt.xlabel(str(attributes[i]))
            plt.ylabel(str(attributes[j]))
            plt.scatter(iris[attributes[i]], iris[attributes[j]], s=20, c="#ff1212", marker='o')
            # 位置加1
            pos = pos + 1

    plt.show()


# 所有属性的q-q图绘制
def drawQQ(iris):
    # Apply the default theme
    sns.set_theme()

    attributes = iris.columns
    pos = 1

    for i in range(len(attributes)):
        for j in range(i+1, len(attributes)):
            plt.subplot(2, 3, pos)
            data1 = sorted(iris[str(attributes[i])])
            data2 = sorted(iris[str(attributes[j])])

            plt.xlabel(str(attributes[i]))
            plt.ylabel(str(attributes[j]))
            sns.regplot(x=data1, y=data2, color='pink')
            # 位置加1
            pos = pos + 1

    plt.show()


# 最大最小归一化
def normalization1(iris, new_min, new_max):
    new_iris = copy.deepcopy(iris)
    for attr in new_iris.columns:
        old_arr = new_iris[str(attr)]
        old_min = min(old_arr)
        old_max = max(old_arr)
        new_iris[str(attr)] = new_min + (old_arr - old_min) * (new_max - new_min) / old_max
    print(new_iris)
    return new_iris


# 零均值归一化
def normalization2(iris):
    new_iris = copy.deepcopy(iris)
    for attr in new_iris.columns:
        old_arr = new_iris[str(attr)]
        # 均值
        mean = np.mean(old_arr)
        # 标准差
        var = np.std(old_arr)
        new_iris[str(attr)] = (old_arr - mean) / var
    print(new_iris)
    return new_iris


if __name__ == '__main__':
    # 导入iris数据集
    init_iris = load_iris()
    labels = init_iris.target
    iris = pd.DataFrame(init_iris.data, columns=['SpealLength', 'SpealWidth', 'PetalLength', 'PetalWidth'])
    # 打印所有属性的五数概括
    print("------------各个属性的五数概括-------------")
    for attr in iris.columns:
        nums = iris[attr]
        minNum, Q1, median, Q3, maxNum = five_num_sum(nums)
        print(attr, minNum, Q1, median, Q3, maxNum)

    # ------------图像绘制------------
    # drawSingleBox(iris['SpealLength'])
    # drawScatter(iris)
    # drawQQ(iris)

    # -------------归一化-----------
    # new_iris = normalization1(iris, 0, 1)
    # drawQQ(new_iris)

    # new_iris = normalization2(iris)
    # drawQQ(new_iris)

    # -------------主成分分析-----------
    # 降到2维，并且复制训练集（不改动它）
    pca = decomposition.PCA(copy=True)
    pca.fit(init_iris.data)
    new_iris = pca.transform(init_iris.data)
    print(pca.explained_variance_ratio_)

    plt.scatter(new_iris[:, 0], new_iris[:, 1], c=labels, cmap=plt.cm.Set1, edgecolor='k', s=40)
    for name, label in [('Setosa', 0), ('Versicolour', 1), ('Virginica', 2)]:
        plt.text(new_iris[labels == label, 0].mean(), new_iris[labels == label, 1].mean(), name, bbox=dict(alpha=.8, edgecolor='w', facecolor='w'))
    plt.xlabel('1st eigenvector')
    plt.ylabel('2st eigenvector')
    plt.show()
