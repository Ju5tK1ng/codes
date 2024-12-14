#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    float ope, high, low, close;
};
float COMMISSION = 0.00005;
int ONE_COST = 10000;
int MAX_COST = 300000;
float START_POSITION = 0.5;
string DATA_PATH = "D:\\gp\\data\\";
string INPUT_PATH = "D:\\codes\\gp_code\\dataDividend.csv";
string OUTPUT_NAME = "Dividend4_" + to_string(int(START_POSITION * 100)) + ".csv";
string line, date;
vector<string> dataList;
vector<DayData> dayDataList;
// vector<string> START_DATE = {"2015-05-29","2020-07-03","2022-03-09","2023-07-31","2024-10-14"}; // 3.8+
vector<string> START_DATE = {"2019-12-20","2020-12-18","2021-12-17","2022-12-16","2023-12-15"}; // 5 year
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
int startSimulation(int dataIndex, vector<float> buyPercent, vector<float> sellPercent, bool output = false)
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
        else if (dataIndex + 1 < START_DATE.size() && dayDataList[i].date == START_DATE[dataIndex + 1])
        {
            break;
        }
        dayData = dayDataList[i];
        date = dayData.date;
        ope = dayData.ope;
        high = dayData.high;
        low = dayData.low;
        close = dayData.close;
        sellPrice = 0;
        dateCnt += 1;
        for (int j = 0; j < sellPercent.size(); j++)
        {
            newPrice = round(ope * (1 + sellPercent[j] / 100));
            if (j < sellPercent.size() - 1 && sellPercent[j] == sellPercent[j + 1])
            {
                newCount = floor(ONE_COST * 2 / newPrice * 10) / 10;
                j++;
            }
            else
            {
                newCount = floor(ONE_COST / newPrice * 10) / 10;
            }
            if (newPrice <= high && cnt > 0)
            {
                newCount = min(newCount, cnt);
                sellPrice += (newPrice * newCount) * (1 - COMMISSION);
                cost = cost + (newPrice * newCount) * (1 - COMMISSION);
                cnt = cnt - newCount;
            }
        }
        if (dayDataList[i].date == START_DATE[dataIndex])
        {
            newPrice = ope;
            newCount = floor(MAX_COST * START_POSITION / newPrice * 10) / 10;
            cost = cost - (newPrice * newCount) * (1 + COMMISSION);
            cnt = cnt + newCount;
        }
        if (cnt == 0)
        {
            totalCost = totalCost + cost;
            cost = 0;
        }
        for (int j = 0; j < buyPercent.size(); j++)
        {
            newPrice = round(ope * (1 - buyPercent[j] / 100));
            if (j < buyPercent.size() - 1 && buyPercent[j] == buyPercent[j + 1])
            {
                newCount = floor(ONE_COST * 2 / newPrice * 10) / 10;
                j++;
            }
            else
            {
                newCount = floor(ONE_COST / newPrice * 10) / 10;
            }
            profit = cost - newPrice * newCount - (close < newPrice ? 0 : sellPrice);
            if (newPrice >= low && profit > -MAX_COST)
            {
                cost = cost - (newPrice * newCount) * (1 + COMMISSION);
                cnt = cnt + newCount;
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
    }
    if (output)
    {
        string simualtionPath = DATA_PATH + START_DATE[dataIndex] + OUTPUT_NAME;
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
    // vector<float> BUY_PERCENT = {0.0,0.3,0.4,0.5,0.6,0.7,0.8,1.2,1.7,1.8,2.1};
    // vector<float> SELL_PERCENT = {0.3,0.4,0.7,0.9,1.0,1.1,1.3,1.6,1.8,2.0};
    // vector<float> BUY_PERCENT = {0.0,0.6,0.7,0.8,1.2,1.7,1.8,2.1};
    // vector<float> SELL_PERCENT = {0.3,0.4,0.9,1.0,1.1,1.3,1.6,1.8,2.0};
    vector<float> BUY_PERCENT = {0.3,0.4,0.5,0.6,0.8,1.2,1.8,2.1};
    vector<float> SELL_PERCENT = {0.3,0.4,0.7,0.9,1.0,1.1,1.6,1.8};
    string progress = "";
    int size = round(pow(3, BUY_PERCENT.size())) * round(pow(3, SELL_PERCENT.size()));
    cout << "size: " << size << endl;
    vector<float> buyPercent;
    vector<float> sellPercent;
    vector<string> profitList;
    int count = 0;
    int startTime = time(nullptr);
    for (int i = 0; i < pow(3, BUY_PERCENT.size()); i++)
    {
        buyPercent.clear();
        for (int t = 0; t < BUY_PERCENT.size(); t++)
        {
            if (i % int(pow(3, t + 1)) / int(pow(3, t)) == 1)
            {
                buyPercent.push_back(BUY_PERCENT[t]);
            }
            else if (i % int(pow(3, t + 1)) / int(pow(3, t)) == 2)
            {
                buyPercent.push_back(BUY_PERCENT[t]);
                buyPercent.push_back(BUY_PERCENT[t]);
            }
        }
        for (int j = 0; j < pow(3, SELL_PERCENT.size()); j++)
        {
            sellPercent.clear();
            for (int t = 0; t < SELL_PERCENT.size(); t++)
            {
                if (j % int(pow(3, t + 1)) / int(pow(3, t)) == 1)
                {
                    sellPercent.push_back(SELL_PERCENT[t]);
                }
                else if (j % int(pow(3, t + 1)) / int(pow(3, t)) == 2)
                {
                    sellPercent.push_back(SELL_PERCENT[t]);
                    sellPercent.push_back(SELL_PERCENT[t]);
                }
            }
            totalProfit = 0;
            count += 1;
            dateCnt = 0;
            for (int k = 0; k < START_DATE.size(); k++)
            {
                float p = startSimulation(k, buyPercent, sellPercent);
                totalProfit += p;
            }
            if (totalProfit > 140000)
            {
                profitList.push_back(vector2Str(buyPercent, 1) + ',' + vector2Str(sellPercent, 1) + ',' + float2Str(totalProfit) + ',' + to_string(dateCnt) + ',' + float2Str(totalProfit / dateCnt));
            }
            if (progress != float2Str((float)count / size * 100, 1))
            {
                progress = float2Str((float)count / size * 100, 1);
                cout << progress << "%  time:" << float2Str((time(nullptr) - startTime) / (float)count * (size - count) / 60)  << endl;
            }
        }
    }
    string totalPath = DATA_PATH + "total" + START_DATE[0] + OUTPUT_NAME;
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}
void simulataOne()
{
    vector<float> buyPercent = {0.6, 1.8, 1.8, 2.1, 2.1};
    vector<float> sellPercent = {1.0, 1.0, 1.6, 1.8, 1.8};
    totalProfit = 0;
    dateCnt = 0;
    for (int k = 0; k < START_DATE.size(); k++)
    {
        float p = startSimulation(k, buyPercent, sellPercent, true);
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
