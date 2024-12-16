#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    double ope, close, pos;
};
string DATA_PATH = "D:\\gp\\data\\tea";
string INPUT_PATH = "D:\\codes\\gp_code\\dataEtfTea.csv";
string OUTPUT_NAME = ".csv";
string line, date;
vector<string> dataList;
vector<DayData> dayDataList;
string float2Str(double f, int decimal = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(decimal) << f;
    return oss.str();
}
string vector2Str(vector<double> vec, int decimal = 2)
{
    string str = "";
    for (double num : vec)
    {
        str += float2Str(num, decimal) + ";";
    }
    str = str.substr(0, str.length() - 1);
    return str;
}
double ope, close, pos, profit, lastClose, lastPos;
int dateCnt;
vector<string> simulationList;
DayData dayData;
double startSimulation(double rate, double offset)
{
    profit = 100;
    pos = 0;
    simulationList.clear();
    simulationList.push_back("date,open,close,pos,profit");
    for (int i = 0; i < dayDataList.size(); i++)
    {
        dayData = dayDataList[i];
        date = dayData.date;
        ope = dayData.ope;
        close = dayData.close;
        line = "";
        if (i != 0)
        {
            profit = profit + profit * lastPos * (ope - lastClose) / lastClose / 100;
            line += "," + float2Str(profit);
            profit = profit + profit * pos * (close - ope) / ope / 100;
            line += "," + float2Str(profit);
        }
        lastClose = close;
        lastPos = pos;
        pos = max(0.0, (dayData.pos - offset) * rate);
        profit = profit - profit * abs(pos - lastPos) / 100 * 0.00005;
        line += "," + float2Str(profit);
        simulationList.push_back(dataList[i + 1] + line);
    }
    string simualtionPath = DATA_PATH + float2Str(rate, 3) + "," + float2Str(offset, 3) + OUTPUT_NAME;
    ofstream simualtionFile(simualtionPath);
    for (string line : simulationList)
    {
        simualtionFile << line << endl;
    }
    simualtionFile.close();
    return profit;
}
void simulataOne()
{
    for (double rate = 0.5; rate <= 5; rate += 0.1)
    {
        double offset = 130 - 100 / rate;
        cout << "profit: " << rate << ", " << offset << ", " << startSimulation(rate, offset) << endl;
    }
    // double rate = 5.0 / 3;
    // double offset = 70;
    // cout << "profit: " << rate << ", " << offset << ", " << startSimulation(rate, offset) << endl;
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
        dayData.close = stof(dataList[i].substr(17, 5)) * 1000;
        dayData.pos = stof(dataList[i].substr(23, 3));
        dayDataList.push_back(dayData);
    }
    simulataOne();
    return 0;
}
