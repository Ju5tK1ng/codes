#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    float ope, high, low, close;
    int base, cent, countBase;
};
int totalProfit = 0;
float COMMISSION = 0.00025;
// float COMMISSION = 0;
string DATA_PATH = "D:\\gp\\code\\data.csv";
// string DATA_PATH = "S:\\codes\\gp\\data.csv";
string line;
char c;
vector<string> dataList;
vector<DayData> dayDataList;
// vector<string> START_DATE = {"2015-03-19"};
// vector<string> START_DATE = {"2015-08-06"};
// vector<string> START_DATE = {"2015-06-08","2016-01-29","2017-10-31","2018-01-31","2019-02-28","2021-02-10","2023-01-31","2024-04-30"};
// vector<string> START_DATE = {"2015-01-05","2016-01-15","2017-02-10","2018-02-28","2019-03-07","2020-03-25","2021-04-20","2022-05-20","2023-06-20"};
// vector<string> START_DATE = {"2015-03-19","2015-08-06","2015-12-25","2017-08-28","2018-02-09","2018-06-07",
//                              "2019-03-06","2019-10-21","2020-05-29","2022-05-09","2023-01-04","2023-09-06"}; // 3800+
vector<string> START_DATE = {"2015-07-16", "2017-10-12", "2018-05-22", "2019-04-01",
                             "2019-11-20", "2020-06-15", "2022-05-06", "2023-08-10"}; // 3900+

string float2Str(float f, int decimal = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(decimal) << f;
    return oss.str();
}
string date;
float ope, high, low, close, newPrice, sellPrice, totalCost, cost, price, profit, point, newCount, cnt;
int base, cent, countBase;
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
                if (j > 0 && sellPercent[j - 1] == sellPercent[j])
                {
                    continue;
                }
                newPrice = ope * (1 + sellPercent[j] / 100);
                newCount = ceil(20000 / newPrice * 10) / 10;
                if (newPrice <= high && (cost == 0 || cost + newPrice * cnt > 0))
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
            if (j > 0 && buyPercent[j - 1] == buyPercent[j])
            {
                continue;
            }
            newPrice = ope * (1 - buyPercent[j] / 100);
            newCount = ceil(20000 / newPrice * 10) / 10;
            profit = totalCost + cost - newPrice * newCount - (close < newPrice ? 0 : sellPrice);
            if (newPrice >= low && (cost == 0 && newPrice < 4000 || cost + newPrice * cnt < 0) && profit > -250000)
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
        string simualtionPath = "D:\\gp\\data\\" + START_DATE[dataIndex] + "II.csv";
        ofstream simualtionFile(simualtionPath);
        for (string line : simulationList)
        {
            simualtionFile << line << endl;
        }
        simualtionFile.close();
    }
    return round(profit);
}
string vector2Str(vector<float> vec)
{
    string str = "";
    for (float num : vec)
    {
        str += float2Str(num) + ";";
    }
    str = str.substr(0, str.length() - 1);
    return str;
}
void simulataAll()
{
    string progress = "";
    int size = 0;
    for (float i = 0; i <= 1; i += 0.1)
    {
        for (float ii = i; ii <= 2.5; ii += 0.1)
        {
            for (float iii = ii; iii <= 4; iii += 0.1)
            {
                for (float j = 0; j <= 2; j += 0.1)
                {
                    for (float jj = j; jj <= 3; jj += 0.1)
                    {
                        // for (float jjj = jj; jjj <= 5; jjj += 0.5)
                        // {
                            size += 1;
                        // }
                    }
                }
            }
        }
    }
    cout << "size: " << size << endl;
    vector<float> buyPercent = {0, 0, 0};
    vector<float> sellPercent = {0, 0};
    vector<string> profitList;
    int count = 0;
    for (float i = 0; i <= 1; i += 0.1)
    {
        buyPercent[0] = i;
        for (float ii = i; ii <= 2.5; ii += 0.1)
        {
            buyPercent[1] = ii;
            for (float iii = ii; iii <= 4; iii += 0.1)
            {
                buyPercent[2] = iii;
                for (float j = 0; j <= 2; j += 0.1)
                {
                    sellPercent[0] = j;
                    for (float jj = j; jj <= 3; jj += 0.1)
                    {
                        sellPercent[1] = jj;
                        // for (float jjj = jj; jjj <= 5; jjj += 0.5)
                        // {
                        // sellPercent[2] = jjj;
                            totalProfit = 0;
                            count += 1;
                            for (int k = 0; k < START_DATE.size(); k++)
                            {
                                totalProfit += startSimulation(k, buyPercent, sellPercent, 0.1);
                            }
                            if (totalProfit > 1100000)
                            {
                                profitList.push_back(vector2Str(buyPercent) + ',' + vector2Str(sellPercent) + ',' + "0.1" + ',' + to_string(totalProfit));
                            }
                            if (progress != float2Str((float)count / size * 100, 1))
                            {
                                progress = float2Str((float)count / size * 100, 1);
                                cout << progress << "%" << endl;
                            }
                        // }
                    }
                }
            }
        }
    }
    string totalPath = "D:\\gp\\data\\totalII" + START_DATE[0] + ".csv";
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}
void simulataOne()
{
    vector<float> buyPercent = {0.0, 0.9, 1.4};
    vector<float> sellPercent = {1.3, 1.5, 5};
    totalProfit = 0;
    for (int k = 0; k < START_DATE.size(); k++)
    {
        totalProfit += startSimulation(k, buyPercent, sellPercent, 0.1, true);
    }
    cout << "totalProfit: " << totalProfit << endl;
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
        dayData.ope = stof(dataList[i].substr(11, 9));
        dayData.high = stof(dataList[i].substr(21, 9));
        dayData.low = stof(dataList[i].substr(31, 9));
        dayData.close = stof(dataList[i].substr(41, 9));
        dayData.base = round(dayData.ope / 1000);
        dayData.cent = dayData.base * 10;
        dayData.countBase = 10 - dayData.base;
        dayDataList.push_back(dayData);
    }
    simulataOne();
    simulataAll();
    return 0;
}
