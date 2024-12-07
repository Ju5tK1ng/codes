#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    float ope, high, low, close;
    int base, cent, countBase;
};
float COMMISSION = 0.00005;
float BUILD_PRICE = 3920;
int ONE_COST = 10000;
int MAX_COST = 300000;
string DATA_PATH = "D:\\codes\\gp_code\\dataEtf.csv";
string line;
char c;
vector<string> dataList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2022-03-09"};
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
string date;
float ope, high, low, close, newPrice, sellPrice, totalCost, cost, price, profit, point, newCount, cnt, totalProfit;
int base, cent, countBase, originalProfit;
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
        // else if (dataIndex + 1 < START_DATE.size() && dayDataList[i].date == START_DATE[dataIndex + 1])
        // {
        //     break;
        // }
        dayData = dayDataList[i];
        date = dayData.date;
        ope = dayData.ope;
        high = dayData.high;
        low = dayData.low;
        close = dayData.close;
        base = dayData.base;
        cent = dayData.cent;
        countBase = dayData.countBase;
        sellPrice = 0;
        if (ope > 4000 && (cost + ope * cnt) > -cost * profitPercent)
        {
            cost = cost + (ope * cnt) * (1 - COMMISSION);
            cnt = 0;
        }
        else
        {
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
            profit = totalCost + cost - newPrice * newCount - (close < newPrice ? 0 : sellPrice);
            if (newPrice >= low && (cost == 0 && newPrice < BUILD_PRICE || cost + newPrice * cnt < 0) && profit > -MAX_COST)
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
        string simualtionPath = "D:\\gp\\data\\" + START_DATE[dataIndex] + "ETF2.csv";
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
    // vector<float> BUY_PERCENT = {0.0,0.1,0.2,0.3,0.4,0.6,0.7,0.9,1.0,1.2,1.3,1.4,1.8,2};
    // vector<float> SELL_PERCENT = {0.4,0.6,1.2,1.9};
    vector<float> BUY_PERCENT = {0.1,0.2,0.3,0.4,0.6,1.0,1.2,1.3,1.4,1.9,2.0};
    vector<float> SELL_PERCENT = {0.4,0.6,1.2,1.9};
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
            originalProfit = 0;
            totalProfit = 0;
            count += 1;
            for (int k = 0; k < START_DATE.size(); k++)
            {
                float p = startSimulation(k, buyPercent, sellPercent, 0.1);
                originalProfit += p;
                totalProfit += p / (START_DATE.size() - k);
            }
            // cout << vector2Str(buyPercent) + ',' + vector2Str(sellPercent) + ',' + "0.1" + ',' + to_string(originalProfit) + ',' + float2Str(totalProfit, 0) << endl;
            if (originalProfit > 121000)
            {
                profitList.push_back(vector2Str(buyPercent, 1) + ',' + vector2Str(sellPercent, 1) + ',' + "0.1" + ',' + to_string(originalProfit) + ',' + float2Str(totalProfit, 0));
            }
            if (progress != float2Str((float)count / size * 100, 1))
            {
                progress = float2Str((float)count / size * 100, 1);
                cout << progress << "%  time:" << float2Str((time(nullptr) - startTime) / (float)count * (size - count) / 60)  << endl;
            }
        }
    }
    string totalPath = "D:\\gp\\data\\total" + START_DATE[0] + "ETF2.csv";
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}
void simulataOne()
{
    vector<float> buyPercent = {0.1,0.1,0.2,0.2,0.4,0.6,1.0,1.3,1.3,1.4,2.0,2.0};
    vector<float> sellPercent = {0.4,0.4,0.6,1.2,1.2};
    originalProfit = 0;
    totalProfit = 0;
    for (int k = 0; k < START_DATE.size(); k++)
    {
        float p = startSimulation(k, buyPercent, sellPercent, 0.1, true);
        originalProfit += p;
        totalProfit += p / (START_DATE.size() - k);
        cout << "p: " << p << endl;
    }
    cout << "originalProfit: " << originalProfit << endl;
    cout << "totalProfit: " << float2Str(totalProfit) << endl;
}
int main()
{
    ifstream dataFile(DATA_PATH);
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
        dayData.base = round(dayData.ope / 1000);
        dayData.cent = dayData.base * 10;
        dayData.countBase = 10 - dayData.base;
        dayDataList.push_back(dayData);
    }
    simulataOne();
    simulataAll();
    return 0;
}
