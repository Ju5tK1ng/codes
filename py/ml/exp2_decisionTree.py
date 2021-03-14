"""
使用CART方法实现决策树
包括连续值
数据为鸢尾花数据集
"""
import copy
from exp2_plotJsonTree import *
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from pycallgraph import PyCallGraph
from pycallgraph.output import GraphvizOutput
from pycallgraph import Config
from pycallgraph import GlobbingFilter

# 导入数据
iris = load_iris()
X = iris.data[:, :]
label = iris.target
Y = []
for i in range(len(label)):
    if label[i] == 0:
        Y.append("setosa")
    elif label[i] == 1:
        Y.append("versicolour")
    else:
        Y.append("virginica")
Y = np.array(Y)

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=35)
trainData = np.concatenate((x_train, y_train.reshape(120, 1)), axis=1)
trainData = pd.DataFrame(trainData, columns=['花萼长度', '花萼宽度', '花瓣长度', '花瓣宽度', '种类'])
trainData.index += 1

testData = np.concatenate((x_test, y_test.reshape(30, 1)), axis=1)
testData = pd.DataFrame(testData, columns=['花萼长度', '花萼宽度', '花瓣长度', '花瓣宽度', '种类'])
testData.index += 1

# str -> float
for feature in trainData.columns[:-1]:
    trainData[feature] = pd.DataFrame(trainData[feature], dtype=np.float)
    testData[feature] = pd.DataFrame(testData[feature], dtype=np.float)

def gini_index_discrete(data, a, target):
    """
    离散值的基尼指数计算
    :param data: input the name of DataFrame
    :param a: the name of feature
    :param target: the name of target
    :return: gini_index
    """
    gini_index = 0        # Gini_index(D ,a)
    attributes = data[a].value_counts()   # 属性a的所有取值
    length = data[a].size   # |D|

    # 对于属性a的每个取值，进行基尼值计算
    for name in data[a].unique():
        kindDict = {}  # 对于每个属性值， 记录每个种类的对应数目
        for kind in data[target].unique():   # initial
            kindDict[kind] = 0

        for index in data.index:
            if data[a].values[index-1] == name:
                kindDict[data[target].values[index-1]] += 1

        # 计算 Gini(D)
        gini = 1
        for key in kindDict.keys():
            gini -= np.square(kindDict[key] / attributes[name])

        gini_index += (attributes[name] / length) * gini

    return gini_index


def gini_index_continuous(data, a, target):
    """
    连续值的基尼指数计算
    :param data: input the name of DataFrame
    :param a: the name of feature
    :param target: the name of target
    :return: gini_index
    """
    gini_index_min = 999999  # Gini_index(D ,a)
    t_best = 0     # 最佳划分点
    length = data[a].size  # |D|
    values = sorted(data[a].values)
    # values.sort()
    # print(values)
    # 对于每一个t值，t = （a（i)+ a(i+1)) /2
    for i in range(length - 1):
        t = np.round((values[i] + values[i+1])/2, 3)
        # print("t=",t)
        kindDict1 = {}  # 存储小于等于t的各个种类对应的数目
        kindDict2 = {}  # 存储大于t的各个种类对应的数目
        for kind in data[target].unique():   # initial
            kindDict1[kind] = 0
            kindDict2[kind] = 0
        # print(data[a].values)
        for index in data.index:
            if data[a].values[index-1] <= t:
                kindDict1[data[target].values[index-1]] += 1
                # print("index=", index)
            else:
                kindDict2[data[target].values[index-1]] += 1

        # 计算Gini
        Dt_n = i + 1           # 小于等于候选划分的样本数
        Dt_p = length - i - 1  # 大于候选划分的样本数
        # print("Dt_n:", Dt_n, " Dt_p:", Dt_p)
        gini_n = 1    # 小于等于候选划分的基尼值
        gini_p = 1    # 大于候选划分的基尼值
        for key in kindDict1.keys():
            gini_n -= np.square(kindDict1[key] / Dt_n)
            gini_p -= np.square(kindDict2[key] / Dt_p)

        # print(kindDict1, kindDict2)
        # print("gini_n=", gini_n, " gini_p=", gini_p)
        gini_index = (Dt_n / length) * gini_n + (Dt_p / length) * gini_p
        # print("gini:", gini_index)
        # 更新gini值 和 划分点t，知道找到最小的gini值
        if gini_index < gini_index_min:
            gini_index_min = gini_index
            t_best = t

    print("对应划分点为： ", t_best)
    return gini_index_min, t_best


def chooseBestFeature(data):
    """
    从所有属性中选择最优划分属性
    :param data: 数据集输入
    :return: 最优划分属性和划分点（连续值的时候）
    """
    gini_index_min = 999999
    pos = 0
    for feature in data.columns[:-1]:
        # print('属性', feature)

        gini_index, pos = gini_index_continuous(data, feature, '种类')

        # print("基尼指数为", gini_index)
        # print()
        if gini_index < gini_index_min:
            gini_index_min = gini_index
            pos_best = pos
            feature_best = feature

    print("最小基尼指数为：", gini_index_min, "属性名称：", feature_best)
    # print("所以应该基于{}划分".format(feature_best))
    return feature_best, pos_best


def JudgeAllEqual(data):
    flag = 1
    labels = list(data.columns[:-1])
    firstline = list(data[label].values[0] for label in labels)
    for index in data.index:
        line = list(data[label].values[index-1] for label in labels)
        if line != firstline:
            flag = 0
            break
    return flag

def splitSubData(data, bestFeatureName, a):
    # Dv = pd.DataFrame()  # 样本子集
    Dv = data[0:0]
    for index in data.index:
        if data[bestFeatureName].values[index - 1] == a:
            Dv = Dv.append(data[index - 1:index])

    Dv = Dv.drop(columns=[bestFeatureName])
    Dv = Dv.reset_index(drop=True)
    Dv.index += 1
    return Dv

def classify(decisionTree, oneTestData):
    """
    给一条测试集打标签
    :param decisionTree: 决策树（Json格式）
    :param testData: DataFrame格式的一条数据
    :return: 类别
    """
    # 当递归到字符串的时候，说明是标签值，直接返回
    if type(decisionTree) == str:
        return decisionTree
    featureName = list(decisionTree.keys())[0]
    value = oneTestData[featureName].values[0]

    first = list(decisionTree[featureName].keys())[0]
    second = list(decisionTree[featureName].keys())[1]
    if first[0] == '<':  # 说明第一个是'<=0.382'
        at = float(first[2:])
        if value <= at:
            subTree = decisionTree[featureName][first]
        else:
            subTree = decisionTree[featureName][second]
    else:               # 说明第一个是'>0.382'
        at = float(first[1:])
        if value <= at:
            subTree = decisionTree[featureName][second]
        else:
            subTree = decisionTree[featureName][first]

    return classify(subTree, oneTestData)

def calAccuracy(decisionTree, testData):
    """
    计算模型精度
    :param decisionTree: 生成的决策树（Json格式）
    :param testData: 测试集
    :return: 精度
    """
    rightCount = 0
    for index in testData.index:
        oneTestData = testData[index-1:index]
        predictLabel = classify(decisionTree, oneTestData)
        if predictLabel == oneTestData["种类"].values[0]:
            rightCount += 1
    return rightCount / len(testData)


def countRightNum(data, label):
    """
    统计data中标签为label的个数
    :param data: 数据集
    :param label: 标签值
    :return: 个数
    """
    count = 0
    for index in data.index:
        if data["种类"].values[index-1] == label:
            count += 1
    return count

def TreeGenerate(data):
    # 当data中样本全属于同一类别
    if len(data["种类"].unique()) == 1:
        print(data["种类"].values[0], "\n")
        return data["种类"].values[0]
    # 属性集合为空，或者data中样本在features中取值全部相等
    if len(data.columns) == 1 or JudgeAllEqual(data):
        print(data["种类"].value_counts(sort=True).index[0], "\n")
        return data["种类"].value_counts(sort=True).index[0]

    bestFeatureName, at = chooseBestFeature(data)
    print("最优特征为：", bestFeatureName)


    Tree = {bestFeatureName: {}}
    subTree = {}
    Dv_n = pd.DataFrame()  # 小于等于划分点的样本子集
    Dv_p = pd.DataFrame()  # 大于划分点的样本子集

    # 划分样本子集
    for index in data.index:
        if data[bestFeatureName].values[index - 1] <= at:
            Dv_n = Dv_n.append(data[index - 1:index])
        else:
            Dv_p = Dv_p.append(data[index - 1:index])

    # 小于等于划分点的分支形成
    Dv_n = Dv_n.drop(columns=[bestFeatureName])
    Dv_n = Dv_n.reset_index(drop=True)
    Dv_n.index += 1

    print()
    print("<=", at)
    print(Dv_n)
    print()
    # 样本子集全部属于一个类别
    if len(Dv_n) == 0:
        mainLabel = data["种类"].value_counts(sort=True).index[0]
        print("******", bestFeatureName, "<=", at, mainLabel)
        subTree["<=" + str(at)] = mainLabel
        Tree[bestFeatureName] = subTree
    else:
        print("******", bestFeatureName, "<=", at, "?")
        subTree["<=" + str(at)] = TreeGenerate(Dv_n)
        Tree[bestFeatureName] = subTree

    # 大于划分点的分支形成
    Dv_p = Dv_p.drop(columns=[bestFeatureName])
    Dv_p = Dv_p.reset_index(drop=True)
    Dv_p.index += 1

    print()
    print(">", at)
    print(Dv_p)
    print()
    # 样本子集全部属于一个类别
    if len(Dv_p) == 0:
        mainLabel = data["种类"].value_counts(sort=True).index[0]
        print("******", bestFeatureName, ">", at, mainLabel)
        subTree[">" + str(at)] = mainLabel
        Tree[bestFeatureName] = subTree
    else:
        print("******", bestFeatureName, ">", at, "?")
        subTree[">" + str(at)] = TreeGenerate(Dv_p)
        Tree[bestFeatureName] = subTree

    return Tree

def main():
    # 生成Json格式的决策树
    decisionTree1 = TreeGenerate(trainData)
    print("产生的树：", decisionTree1)
    print("验证集精度：", calAccuracy(decisionTree1, testData))


    # 绘制决策树
    plt.rcParams['font.sans-serif'] = ['SimHei']
    createPlot(decisionTree1)

if __name__ == '__main__':
    config = Config()
    # 关系图中包括(include)哪些函数名。
    #如果是某一类的函数，例如类gobang，则可以直接写'gobang.*'，表示以gobang.开头的所有函数。（利用正则表达式）。
    # config.trace_filter = GlobbingFilter(include=[
    #     'main',
    #     'TreeGenerate_Notpruning',
    #     'TreeGenerate_Prepruning',
    #     'TreeGenerate_Postpruning',
    #     'JudgeEqual',
    #     'ChooseBestAttribute',
    #     'GiniIndexCalc',
    #     'SplitSubTree',
    #     'RightCount',
    #     'AccuracyCal',
    #     'JudgeResult',
    # ])
    # 该段作用是关系图中不包括(exclude)哪些函数。(正则表达式规则)
    # config.trace_filter = GlobbingFilter(exclude=[
    #     'pycallgraph.*',
    #     '*.secret_function',
    #     'FileFinder.*',
    #     'ModuleLockManager.*',
    #     'SourceFilLoader.*'
    # ])
    graphviz = GraphvizOutput()
    graphviz.output_file = 'graph.png'
    with PyCallGraph(output=graphviz, config=config):
        main()