#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    double ope, high, low, close;
};
string INPUT_PATH = "D:\\codes\\gp_code\\dataGold.csv";
string OUTPUT_PATH = "D:\\gp\\data\\inOrOut.csv";
string line;
vector<string> dataList, simulationList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2013-07-30"};
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
int main()
{
    ifstream dataFile(INPUT_PATH);
    while (getline(dataFile, line)) {
        dataList.push_back(line);
    }
    dataFile.close();
    map<int, int> percent2CntMap;
    percent2CntMap.clear();
    bool start = false;
    double cnt =  0;
    int interval = 1;
    double ope_close = 100;
    double close_ope = 100;
    double lastClose, startClose;
    simulationList.clear();
    simulationList.push_back("date,open,high,low,close,close_ope,ope_close,profit");
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
            startClose = lastClose;
        }
        if (start)
        {
            ope_close = ope_close / dayData.ope * dayData.close;
            close_ope = close_ope / lastClose * dayData.ope;
            simulationList.push_back(dataList[i] + "," + float2Str(close_ope, 3) + "," + float2Str(ope_close, 3) + "," + float2Str(close_ope * ope_close / 100, 3));
        }
        lastClose = dayData.close;
    }
    cout << "close_ope: " << float2Str(close_ope, 3) << endl;
    cout << "ope_close: " << float2Str(ope_close, 3) << endl;
    cout << dayDataList[dayDataList.size() - 1].close << " / " << startClose << endl;
    cout << "close_close: " << float2Str(dayDataList[dayDataList.size() - 1].close / startClose, 3) << endl;
    string simualtionPath = OUTPUT_PATH;
    ofstream simualtionFile(simualtionPath);
    for (string line : simulationList)
    {
        simualtionFile << line << endl;
    }
    simualtionFile.close();
    return 0;
}
