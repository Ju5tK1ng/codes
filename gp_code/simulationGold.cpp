#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    float ope, high, low, close;
};
float COMMISSION = 0.00005;
int ONE_COST = 30000;
int MAX_COST = 120000;
string DATA_PATH = "D:\\codes\\gp_code\\dataGold.csv";
// string DATA_PATH = "S:\\codes\\gp\\dataEtf.csv";
string line;
char c;
vector<string> dataList;
vector<DayData> dayDataList;
// vector<string> START_DATE = {"2023-07-31"};
vector<string> START_DATE = {"2020-01-02","2021-01-04","2022-01-04","2023-01-03","2024-01-02"}; //
// vector<string> START_DATE = {"2018-01-02","2019-01-02","2020-01-02","2021-01-04","2022-01-04","2023-01-03","2024-01-02"}; //
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
        string simualtionPath = "D:\\gp\\data\\" + START_DATE[dataIndex] + "Gold.csv";
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
                for (float iii = ii; iii < 2.2; iii += 0.1)
                {
                    // for (float iiii = iii; iiii < 3; iiii += 0.1)
                    // {
                        for (float j = 0; j < 1.1; j += 0.1)
                        {
                            for (float jj = j; jj < 1.6; jj += 0.1)
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
                for (float iii = ii; iii < 2.2; iii += 0.1)
                {
                    buyPercent[3] = iii;
                    // for (float iiii = iii; iiii < 3; iiii += 0.1)
                    // {
                    //     buyPercent[4] = iiii;
                        for (float j = 0; j < 1.1; j += 0.1)
                        {
                            sellPercent[0] = j;
                            for (float jj = j; jj < 1.6; jj += 0.1)
                            {
                                sellPercent[1] = jj;
                                for (float jjj = jj; jjj < 2.1; jjj += 0.1)
                                {
                                    sellPercent[2] = jjj;
                                    totalProfit = 0;
                                    count += 1;
                                    for (int k = 0; k < START_DATE.size(); k++)
                                    {
                                        float p = startSimulation(k, buyPercent, sellPercent, 0.1);
                                        totalProfit += p;
                                    }
                                    if (totalProfit > 78000)
                                    {
                                        profitList.push_back(vector2Str(buyPercent) + ',' + vector2Str(sellPercent) + ',' + float2Str(totalProfit, 0));
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
    string totalPath = "D:\\gp\\data\\total" + START_DATE[0] + "Gold.csv";
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}
void simulataOne()
{
    vector<float> buyPercent = {0.3, 0.5, 0.8, 1.1};
    vector<float> sellPercent = {0.5, 0.8, 1.1};
    totalProfit = 0;
    for (int k = 0; k < START_DATE.size(); k++)
    {
        float p = startSimulation(k, buyPercent, sellPercent, 0.1, true);
        totalProfit += p;
    }
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
        dayDataList.push_back(dayData);
    }
    simulataOne();
    simulataAll();
    return 0;
}
