#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    float ope, high, low, close;
};
float COMMISSION = 0.00005;
float BUILD_PRICE = 3947;
int ONE_COST = 20000;
int MAX_COST = 300000;
string DATA_PATH = "D:\\gp\\data\\";
string INPUT_PATH = DATA_PATH + "dataEtf.csv";
string line, date;
vector<string> dataList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2015-05-29",};
// vector<string> START_DATE = {"2015-05-29","2020-07-03","2022-03-09","2023-07-31","2024-10-14"}; // 3.8+
// vector<string> START_DATE = {"2019-12-20","2020-12-18","2021-12-17","2022-12-16","2023-12-15"}; // 5 year
string float2Str(float f, int decimal = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(decimal) << f;
    return oss.str();
}
string vector2Str(vector<float> vec, int decimal = 2)
{
    string str = "";
    for (float num : vec)
    {
        str += float2Str(num, decimal) + ";";
    }
    str = str.substr(0, str.length() - 1);
    return str;
}
float ope, high, low, close, newPrice, sellPrice, totalCost, cost, price, profit, point, newCount, cnt, totalProfit;
int dateCnt;
vector<string> simulationList;
DayData dayData;
int startSimulation(int dataIndex, vector<float> buyPercent, vector<float> sellPercent, float profitPercent = 1.5, bool output = false)
{
    totalCost = 0;
    cost = 0;
    cnt = 0;
    price = 0;
    profit = 0;
    point = 0;
    simulationList.clear();
    simulationList.push_back("date,open,high,low,close,totalCost,cost,cnt,price,profit,point");
    bool start = false;
    bool startBuild = true;
    for (int i = 0; i < dayDataList.size(); i++)
    {
        if (dayDataList[i].date == START_DATE[dataIndex])
        {
            start = true;
        }
        if (!start)
        {
            continue;
        }
        dayData = dayDataList[i];
        date = dayData.date;
        ope = dayData.ope;
        high = dayData.high;
        low = dayData.low;
        close = dayData.close;
        sellPrice = 0;
        dateCnt += 1;
        if (ope > 4000 && (cost + ope * cnt) > -cost * profitPercent)
        {
            cost = cost + (ope * cnt) * (1 - COMMISSION);
            cnt = 0;
        }
        else
        {
            for (int j = 0; j < sellPercent.size(); j++)
            {
                if (j > 0 && sellPercent[j - 1] == sellPercent[j])
                {
                    continue;
                }
                newPrice = round(ope * (1 + sellPercent[j] / 100));
                newCount = floor(ONE_COST / newPrice * 10) / 10;
                if (newPrice <= high && cnt > 0 && cost + newPrice * cnt > 0)
                {
                    newCount = min(newCount, cnt);
                    sellPrice += (newPrice * newCount) * (1 - COMMISSION);
                    cost = cost + (newPrice * newCount) * (1 - COMMISSION);
                    cnt = cnt - newCount;
                }
            }
        }
        if (cnt == 0)
        {
            totalCost = totalCost + cost;
            cost = 0;
        }
        for (int j = 0; j < buyPercent.size(); j++)
        {
            // if (j > 0 && buyPercent[j - 1] == buyPercent[j])
            // {
            //     continue;
            // }
            newPrice = round(ope * (1 - buyPercent[j] / 100));
            newCount = floor(ONE_COST / newPrice * 10) / 10;
            profit = cost - newPrice * newCount - (close < newPrice ? 0 : sellPrice);
            if (newPrice >= low && (startBuild || cost + newPrice * cnt < 0) && profit > -MAX_COST)
            {
                cost = cost - (newPrice * newCount) * (1 + COMMISSION);
                cnt = cnt + newCount;
                startBuild = false;
            }
        }
        price = close * cnt;
        profit = totalCost + cost + price;
        if (cost == 0)
        {
            point = 0;
        }
        else
        {
            point = round((cost + price) / -cost * 100) / 100;
        }
        if (output)
        {
            simulationList.push_back(dataList[i + 1] + "," + float2Str(totalCost) + "," + float2Str(cost) + "," + float2Str(cnt, 1) + "," + float2Str(price) + "," + float2Str(profit) + "," + float2Str(point));
        }
        if (cost == 0)
        {
            break;
        }
    }
    if (output)
    {
        string simualtionPath = DATA_PATH + START_DATE[dataIndex] + "ETF3.csv";
        ofstream simualtionFile(simualtionPath);
        for (string line : simulationList)
        {
            simualtionFile << line << endl;
        }
        simualtionFile.close();
    }
    return round(profit);
}
void simulataAll()
{
    string progress = "";
    int size = 0;
    for (float i0 = 0; i0 < 0.7; i0 += 0.1)
    {
        for (float i = i0; i < 1.2; i += 0.1)
        {
            for (float ii = i; ii < 1.7; ii += 0.1)
            {
                for (float iii = ii; iii < 2.1; iii += 0.1)
                {
                    // for (float iiii = iii; iiii < 3; iiii += 0.1)
                    // {
                    //     buyPercent[4] = iiii;
                        for (float j = 0.4; j < 0.9; j += 0.1)
                        {
                            for (float jj = j; jj < 1.5; jj += 0.1)
                            {
                                for (float jjj = jj; jjj < 2.1; jjj += 0.1)
                                {
                                    size += 1;
                                }
                            }
                        }
                    // }
                }
            }
        }
    }
    cout << "size: " << size << endl;
    vector<float> buyPercent = {0, 0, 0, 0};
    vector<float> sellPercent = {0, 0, 0};
    vector<string> profitList;
    int count = 0;
    int startTime = time(nullptr);
    for (float i0 = 0; i0 < 0.7; i0 += 0.1)
    {
        buyPercent[0] = i0;
        for (float i = i0; i < 1.2; i += 0.1)
        {
            buyPercent[1] = i;
            for (float ii = i; ii < 1.7; ii += 0.1)
            {
                buyPercent[2] = ii;
                for (float iii = ii; iii < 2.1; iii += 0.1)
                {
                    buyPercent[3] = iii;
                    // for (float iiii = iii; iiii < 3; iiii += 0.1)
                    // {
                    //     buyPercent[4] = iiii;
                        for (float j = 0.4; j < 0.9; j += 0.1)
                        {
                            sellPercent[0] = j;
                            for (float jj = j; jj < 1.5; jj += 0.1)
                            {
                                sellPercent[1] = jj;
                                for (float jjj = jj; jjj < 2.1; jjj += 0.1)
                                {
                                    sellPercent[2] = jjj;
                                    totalProfit = 0;
                                    count += 1;
                                    dateCnt = 0;
                                    for (int k = 0; k < START_DATE.size(); k++)
                                    {
                                        float p = startSimulation(k, buyPercent, sellPercent, 0.1);
                                        totalProfit += p;
                                    }
                                    if (totalProfit / dateCnt > 300)
                                    {
                                        profitList.push_back(vector2Str(buyPercent) + ',' + vector2Str(sellPercent) + ',' + to_string(START_DATE.size()) + ',' + to_string(dateCnt) + ',' + float2Str(totalProfit / dateCnt));
                                    }
                                    if (progress != float2Str((float)count / size * 100, 1))
                                    {
                                        progress = float2Str((float)count / size * 100, 1);
                                        cout << progress << "%  time:" << float2Str((time(nullptr) - startTime) / (float)count * (size - count) / 60)  << endl;
                                    }
                                }
                            }
                        }
                    // }
                }
            }
        }
    }
    string totalPath = DATA_PATH + "total" + START_DATE[0] + "ETF3.csv";
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}
void simulataOne()
{
    vector<float> buyPercent = {0.4, 0.7, 0.7, 1.3, 1.4};
    vector<float> sellPercent = {0.5, 1.3, 7.1};
    totalProfit = 0;
    dateCnt = 0;
    for (int k = 0; k < START_DATE.size(); k++)
    {
        float p = startSimulation(k, buyPercent, sellPercent, 0.1, true);
        totalProfit += p;
        cout << "p: " << p << endl;
    }
    cout << "totalProfit: " << float2Str(totalProfit) << endl;
    cout << "dateCnt: " << dateCnt << endl;
    cout << "oneDayProfit: " << float2Str(totalProfit / dateCnt) << endl;
}
int main()
{
    ifstream dataFile(INPUT_PATH);
    while (getline(dataFile, line)) {
        dataList.push_back(line);
    }
    dataFile.close();
    for (int i = 1; i < dataList.size(); i++)
    {
        DayData dayData;
        string str = dataList[i];
        dayData.date = dataList[i].substr(0, 10);
        dayData.ope = stof(dataList[i].substr(11, 5)) * 1000;
        dayData.high = stof(dataList[i].substr(17, 5)) * 1000;
        dayData.low = stof(dataList[i].substr(23, 5)) * 1000;
        dayData.close = stof(dataList[i].substr(29, 5)) * 1000;
        dayDataList.push_back(dayData);
    }
    simulataOne();
    simulataAll();
    return 0;
}
