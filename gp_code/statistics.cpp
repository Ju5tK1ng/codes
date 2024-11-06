#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    double ope, high, low, close;
    int base, cent, countBase;
};
string DATA_PATH = "D:\\gp\\code\\dataEtfTest.csv";
// string DATA_PATH = "S:\\codes\\gp\\dataEtf.csv";
string line;
vector<string> dataList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2022-03-09"};
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
double normalCFD(double value)
{
    return 0.5 * erfc(-value * sqrt(2));
}
int main()
{
    ifstream dataFile(DATA_PATH);
    while (getline(dataFile, line)) {
        dataList.push_back(line);
    }
    dataFile.close();
    map<double, int> percent2CntMap;
    percent2CntMap.clear();
    bool start = false;
    double cnt =  0;
    double interval = 0.1;
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
        if (dayData.date == START_DATE[0])
        {
            start = true;
        }
        if (start)
        {
            double percent = floor((dayData.high - dayData.ope) / dayData.ope * 100 / interval) * interval;
            percent2CntMap[percent] += 1;
            percent = ceil((dayData.low - dayData.ope) / dayData.ope * 100 / interval) * interval;
            percent2CntMap[percent] += 1;
            cnt += 2;
        }
    }
    string totalPath = "D:\\gp\\data\\statistics" + START_DATE[0] + '_' + float2Str(interval) + ".csv";
    ofstream totalFile(totalPath);
    // int lastCnt = 0;
    // for (auto it = percent2CntMap.begin(); it != percent2CntMap.end(); it++)
    // {
    //     if (it->first <= 0)
    //     {
    //         it->second += lastCnt;
    //     }
    //     lastCnt = it->second;
    // }
    // lastCnt = 0;
    // for (auto it = percent2CntMap.rbegin(); it != percent2CntMap.rend(); it++)
    // {
    //     if (it->first > 0)
    //     {
    //         it->second += lastCnt;
    //     }
    //     lastCnt = it->second;
    // }
    for (auto it : percent2CntMap)
    {
        double percent = it.second / cnt * 200;
        double percentAbs = abs(it.first);
        double percentNormal = (normalCFD(percentAbs / 5) - normalCFD((percentAbs - interval) / 5)) * 200;
        totalFile << it.first << ',' << it.second << ',' << float2Str(percent) << ',' << float2Str((percentAbs + 1.0857) * it.second, 1) << endl;
    }
    totalFile.close();
    return 0;
}
