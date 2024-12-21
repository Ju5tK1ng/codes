#include <bits/stdc++.h>
using namespace std;
struct DayData
{
    string date;
    double ope, high, low, close;
};
string INPUT_PATH = "D:\\gp\\data\\";
string OUTPUT_PATH = "D:\\gp\\data\\inOrOut";
string line;
vector<string> idList = {"510310", "515180", "512880", "518880", "513090", "159545", "513910", "513260", "159636", "159792", "159985", "513730",
                         "159696", "513390", "159660", "513850", "513500", };
vector<string> dataList, simulationList, resultList, resultAllList;
vector<DayData> dayDataList;
vector<string> START_DATE = {"2024-10-08"};
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
string calcOne(string id, bool start)
{
    dataList.clear();
    ifstream dataFile(INPUT_PATH + id + ".csv");
    while (getline(dataFile, line)) {
        dataList.push_back(line);
    }
    dataFile.close();
    int cnt =  0;
    double ope_close = 100;
    double close_ope = 100;
    double profit;
    double lastClose = 0;
    simulationList.clear();
    simulationList.push_back("date,open,close,close_ope,ope_close,profit");
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
                else
                {
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
        if (start && lastClose != 0)
        {
            cnt += 1;
            ope_close = ope_close / dayData.ope * dayData.close;
            close_ope = close_ope / lastClose * dayData.ope;
            profit = close_ope * ope_close / 100;
            simulationList.push_back(dataList[i] + "," + float2Str(close_ope, 3) + "," + float2Str(ope_close, 3) + "," + float2Str(profit, 3));
        }
        lastClose = dayData.close;
    }
    string simualtionPath = OUTPUT_PATH + id + ".csv";
    ofstream simulationFile(simualtionPath);
    for (string line : simulationList)
    {
        simulationFile << line << endl;
    }
    simulationFile.close();
    return id + "," + float2Str(close_ope, 3) + "," + float2Str(ope_close, 3) + "," + float2Str(profit, 3) + "," + to_string(cnt) + "," + float2Str((close_ope - 100) / cnt, 3) + "," + float2Str((ope_close - 100) / cnt, 3) + "," + float2Str((profit - 100) / cnt, 3);
}

int main()
{
    resultAllList.clear();
    resultAllList.push_back("id,close_ope,ope_close,profit,cnt,c2o,o2c,avg");
    resultList.clear();
    resultList.push_back("id,close_ope,ope_close,profit,cnt,c2o,o2c,avg");
    for (string id : idList)
    {
        string resultAll = calcOne(id, true);
        resultAllList.push_back(resultAll);

        string result = calcOne(id, false);
        cout << result << endl;
        resultList.push_back(result);
    }

    string resultAllPath = OUTPUT_PATH + ".csv";
    ofstream resultAllFile(resultAllPath);
    for (string line : resultAllList)
    {
        resultAllFile << line << endl;
    }
    resultAllFile.close();

    string resultPath = OUTPUT_PATH + START_DATE[0] + ".csv";
    ofstream resultFile(resultPath);
    for (string line : resultList)
    {
        resultFile << line << endl;
    }
    resultFile.close();
    return 0;
}
