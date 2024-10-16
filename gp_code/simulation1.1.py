import numpy as np
import pandas as pd
data = pd.read_csv("D:\\gp\\data\\data.csv")
commission = 0.00025
strategy = [0, 1]
# startDate = ["2015-06-08","2016-01-29","2017-10-31","2018-01-31","2019-02-28","2021-02-10","2023-01-31","2024-04-30"]
startDate = ["2015-03-18"]
def startSimulation(dateIndex, buyPercent, sellPercent):
    totalCost = 0
    cost = 0
    count = 0
    price = 0
    profit = 0
    ratio = 0
    # outputData = []
    # with open("D:\\gp\\data\\data.csv", 'r') as file:
    #     for line in file:
    #         outputData.append(line.replace("\n", ""))
    # outputData[0] = "date,open,high,low,close,totalCost,cost,count,price,profit,ratio"
    rowIndex, columnIndex = np.where(data.values == startDate[dateIndex])
    startIndex = rowIndex[0]
    for i in range(startIndex, len(data)):
        ope = float(data['open'][i])
        high = float(data['high'][i])
        low = float(data['low'][i])
        close = float(data['close'][i])
        base = round(ope / 1000)
        centi = base * 10
        countBase = 10 - base
        if ope > 4000 and (cost + ope * count) > cost * 0.1:
            cost = cost + (ope * count) * (1 - commission)
            count = 0
        else:
            for j in range(0, len(sellPercent)):
                if j > 0 and sellPercent[j - 1] == sellPercent[j]:
                    continue
                newCount = countBase
                newPrice = ope + centi * sellPercent[j]
                # if cost > ope * count:
                #     newPrice = newPrice + centi * 0.5
                if newPrice < high:
                    if newCount > count:
                        newCount = count
                    cost = cost + (newPrice * newCount) * (1 - commission)
                    count = count - newCount
        if count == 0:
            totalCost = round(totalCost + cost, 2)
            cost = 0
        for j in range(0, len(buyPercent)):
            if j > 0 and buyPercent[j - 1] == buyPercent[j]:
                continue
            newCount = countBase
            newPrice = ope - centi * buyPercent[j]
            # if cost < ope * count:
            #     newPrice = newPrice + centi * 2
            if newPrice > low and totalCost + cost - newPrice * newCount > -320000:
                cost = cost - (newPrice * newCount) * (1 + commission)
                count = count + newCount
        cost = round(cost, 2)
        price = round(close * count, 2)
        profit = round(totalCost + cost + price, 2)
        # if cost == 0:
        #     ratio = 0
        # else:
        #     ratio = round((cost + price) / -cost, 2)
        # outputData[i + 1] = outputData[i + 1] + "," + str(totalCost) + "," + str(cost) + "," + str(count) + "," + str(price) + "," + str(profit) + "," + str(ratio)
    # date = startDate[dateIndex]
    # outputFile = "D:\\gp\\data\\" + date + str(strategy) + ".csv"
    # with open(outputFile, 'w') as file:
    #     file.write('\n'.join(outputData))
    return profit

progress = -1
size = 0
for i in range(0, 20):
    for ii in range(i, 31):
        for j in range(0, 20):
            for jj in range(j, 31):
                size = size + 1
print(size)
totalProfit = 0
buyPercent = [0, 0]
sellPercent =  [0, 0]
outputProfit = []
for i in range(0, 20):
    buyPercent[0] = i / 10
    for ii in range(i, 31):
        buyPercent[1] = ii / 10
        for j in range(0, 20):
            sellPercent[0] = j / 10
            for jj in range(j, 31):
                sellPercent[1] = jj / 10
                totalProfit = 0
                for k in range(0, len(startDate)):
                    totalProfit += startSimulation(k, buyPercent, sellPercent)
                outputProfit.append(str(buyPercent).replace(',', ';') + "," + str(sellPercent).replace(',', ';') + "," + str(totalProfit))

                if progress != round(len(outputProfit) / size, 2):
                    progress = round(len(outputProfit) / size, 2)
                    print(progress)


outputFile = "D:\\gp\\data\\" + "total.csv"
with open(outputFile, 'w') as file:
    file.write('\n'.join(outputProfit))
