#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    double ope, close, high, low;
};
double COMMISSION = 0.00005;
string INPUT_PATH = "D:\\gp\\data\\";
string OUTPUT_PATH = "D:\\gp\\data\\simulationO2C";
string line;
string id = "512880";
vector<string> dataList, simulationList, resultList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2023-01-03"};
// vector<string> START_DATE = {"2015-05-29","2020-07-03","2022-03-09","2023-07-31","2024-10-14"}; // 3.8+
string float2Str(double f, int decimal = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(decimal) << f;
    return oss.str();
}
string vector2Str(vector<double> vec)
{
    string str = "";
    for (double num : vec)
    {
        str += float2Str(num) + ";";
    }
    str = str.substr(0, str.length() - 1);
    return str;
}
string calcOne(string id, double buyRate)
{
    dataList.clear();
    ifstream dataFile(INPUT_PATH + id + ".csv");
    while (getline(dataFile, line)) {
        dataList.push_back(line);
    }
    dataFile.close();
    int cnt =  0;
    double ope_close = 100;
    double profit = 100, o2c;
    double lastClose = 0, buy = 0, sell;
    bool start = true;
    simulationList.clear();
    simulationList.push_back("date,open,close,high,o2c,ope_close,buy,sell,profit");
    for (int i = 1; i < dataList.size(); i++)
    {
        DayData dayData;
        string str = dataList[i];
        string num = "";
        int commaCnt = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ',')
            {
                commaCnt += 1;
                if (commaCnt == 1)
                {
                    dayData.date = num;
                }
                else if (commaCnt == 2)
                {
                    dayData.ope = stod(num) * 1000;
                }
                else if (commaCnt == 3)
                {
                    dayData.close = stod(num) * 1000;
                }
                else if (commaCnt == 4)
                {
                    dayData.high = stod(num) * 1000;
                    dataList[i] = dataList[i].substr(0, j);
                    break;
                }
                num = "";
            }
            else
            {
                num += str[j];
            }
        }
        dayDataList.push_back(dayData);
        if (dayData.date == START_DATE[0])
        {
            start = true;
        }
        if (start)
        {
            cnt += 1;
            buy = dayData.ope;
            sell = round(buy * buyRate);
            o2c = dayData.close / dayData.ope;
            ope_close = ope_close * o2c;
            if (sell <= dayData.high)
            {
                profit = profit / buy * sell * (1 - COMMISSION * 2);
            }
            else
            {
                profit = profit / buy * dayData.close * (1 - COMMISSION * 2);
            }
            simulationList.push_back(dataList[i] + "," + float2Str(o2c, 3) + "," + float2Str(ope_close, 3) + "," + float2Str(buy, 0) + "," + float2Str(sell, 0) + "," + float2Str(profit, 3));
        }
    }
    string simualtionPath = OUTPUT_PATH + id + "_" + float2Str(buyRate, 3) + ".csv";
    ofstream simulationFile(simualtionPath);
    for (string line : simulationList)
    {
        simulationFile << line << endl;
    }
    simulationFile.close();
    string result = id + "," + float2Str(ope_close, 3) + "," + to_string(cnt) + "," + float2Str(buyRate, 3) + "," + float2Str(profit, 3) + "," + float2Str((profit - 100) / cnt, 3);
    return result;
}

int main()
{
    resultList.clear();
    resultList.push_back("id,ope_close,cnt,buyRate,profit,avg");
    for (double i = 1.000; i < 1.040; i += 0.001)
    {
        string result = calcOne(id, i);
        cout << result << endl;
        resultList.push_back(result);
    }

    string resultPath = OUTPUT_PATH + START_DATE[0] + ".csv";
    ofstream resultFile(resultPath);
    for (string line : resultList)
    {
        resultFile << line << endl;
    }
    resultFile.close();
    return 0;
}
