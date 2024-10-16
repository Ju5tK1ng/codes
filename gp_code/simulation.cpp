#include <bits/stdc++.h>
using namespace std;

struct DayData
{
    string date;
    float ope, high, low, close;
    int base, centi, countBase;
};

float COMMISSION = 0.0025;
// float COMMISSION = 0;
string DATA_PATH = "D:\\gp\\data\\data.csv";
string line;
stringstream ss;
char c;
vector<string> dataList;
vector<DayData> dayDataList;
// vector<string> START_DATE = {"2015-03-18"};
// vector<string> START_DATE = {"2017-09-05"};
vector<string> START_DATE = {"2015-06-08","2016-01-29","2017-10-31","2018-01-31","2019-02-28","2021-02-10","2023-01-31","2024-04-30"};

string float2Str(float f, int decimal = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(decimal) << f;
    return oss.str();
}

int startSimulation(int dataIndex, vector<float> buyPercent, vector<float> sellPercent, float profitPercent = 1.5, bool output = false)
{
    string date;
    float ope, high, low, close, newPrice, sellPrice;
    int base, centi, countBase, newCount;

    float totalCost = 0;
    float cost = 0;
    int count = 0;
    float price = 0;
    float profit = 0;
    float ratio = 0;
    vector<string> simulationList;
    simulationList.push_back("date,open,high,low,close,totalCost,cost,count,price,profit,ratio");
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
        DayData dayData = dayDataList[i];
        date = dayData.date;
        ope = dayData.ope;
        high = dayData.high;
        low = dayData.low;
        close = dayData.close;
        base = dayData.base;
        centi = dayData.centi;
        countBase = dayData.countBase;
        sellPrice = 0;
        // if (ope > 4000 && (cost + ope * count) > -cost * (2.1 - ope / 5000))
        if (ope > 4000 && (cost + ope * count) > -cost * profitPercent)
        {
            cost = cost + (ope * count) * (1 - COMMISSION);
            count = 0;
        }
        else
        {
            for (int j = 0; j < sellPercent.size(); j++)
            {
                if (j > 0 && sellPercent[j - 1] == sellPercent[j])
                {
                    continue;
                }
                newCount = countBase;
                newPrice = ope + centi * sellPercent[j];
                if (newPrice <= high && (cost == 0 || cost + newPrice * count > 0))
                {
                    newCount = min(newCount, count);

                    sellPrice += (newPrice * newCount) * (1 - COMMISSION);
                    cost = cost + (newPrice * newCount) * (1 - COMMISSION);
                    count = count - newCount;
                }
            }
        }
        if (count == 0)
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
            newCount = countBase;
            newPrice = ope - centi * buyPercent[j];
            profit = totalCost + cost - newPrice * newCount - (close < newPrice ? 0 : sellPrice);
            if (newPrice >= low && (cost == 0 || cost + newPrice * count < 0) && profit > -320000)
            {
                cost = cost - (newPrice * newCount) * (1 + COMMISSION);
                count = count + newCount;
            }
        }
        price = close * count;
        profit = totalCost + cost + price;
        if (cost == 0)
        {
            ratio = 0;
        }
        else
        {
            ratio = round((cost + price) / -cost * 100) / 100;
        }
        if (output)
        {
            simulationList.push_back(dataList[i + 1] + "," + float2Str(totalCost) + "," + float2Str(cost) + "," + to_string(count) + "," + float2Str(price) + "," + float2Str(profit) + "," + float2Str(ratio));
        }
    }
    if (output)
    {
        string simualtionPath = "D:\\gp\\data\\" + START_DATE[dataIndex] + ".csv";
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
    float size = 0;
    for (float i = 0; i <= 2; i += 0.1)
    {
        for (float ii = i; ii <= 3; ii += 0.1)
        {
            for (float j = 0; j <= 2; j += 0.1)
            {
                for (float jj = j; jj <= 3; jj += 0.1)
                {
                    size += 1;
                }
            }
        }
    }
    cout << "size: " << size << endl;

    int totalProfit = 0;
    vector<float> buyPercent = {0, 0};
    vector<float> sellPercent = {0, 0};
    vector<string> profitList;
    for (float i = 0; i <= 2; i += 0.1)
    {
        buyPercent[0] = i;
        for (float ii = i; ii <= 3; ii += 0.1)
        {
            buyPercent[1] = ii;
            for (float j = 0; j <= 2; j += 0.1)
            {
                sellPercent[0] = j;
                for (float jj = j; jj <= 3; jj += 0.1)
                {
                    sellPercent[1] = jj;
                    for (float x = 1; x <= 3; x += 0.1)
                    {
                        totalProfit = 0;
                        for (int k = 0; k < START_DATE.size(); k++)
                        {
                            totalProfit += startSimulation(k, buyPercent, sellPercent, x);
                        }
                        profitList.push_back(vector2Str(buyPercent) + ',' + vector2Str(sellPercent) + ',' + float2Str(x) + ',' + to_string(totalProfit));
                    }
                    if (progress != float2Str(profitList.size() / size * 100, 0))
                    {
                        progress = float2Str(profitList.size() / size * 100, 0);
                        cout << progress << "%" << endl;
                    }
                }
            }
        }
    }

    string totalPath = "D:\\gp\\data\\total" + START_DATE[0] + ".csv";
    ofstream totalFile(totalPath);
    for (string line : profitList)
    {
        totalFile << line << endl;
    }
    totalFile.close();
}

void simulataOne()
{
    vector<float> buyPercent = {0, 0.4};
    vector<float> sellPercent = {1.1, 2.5};
    startSimulation(0, buyPercent, sellPercent, 1.5, true);
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
        dayData.centi = dayData.base * 10;
        dayData.countBase = 10 - dayData.base;
        dayDataList.push_back(dayData);
    }

    simulataOne();
    simulataAll();

    return 0;
}
