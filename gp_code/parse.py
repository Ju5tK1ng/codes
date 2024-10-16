import baostock as bs
import pandas as pd
lg = bs.login()
print('login respond error_code:'+lg.error_code)
print('login respond  error_msg:'+lg.error_msg)
rs = bs.query_history_k_data_plus("sh.000300",
    "date,open,high,low,close",
    # "date,code,open,high,low,close,volume,amount,adjustflag",
    # start_date='2021-07-01',
    frequency="d", adjustflag="3")
print('query_history_k_data_plus respond error_code:'+rs.error_code)
print('query_history_k_data_plus respond  error_msg:'+rs.error_msg)
# rs = bs.query_history_k_data_plus("sh.510310",
#     "date,time,code,open,high,low,close,volume,amount,adjustflag",
#     start_date='2021-07-01',
#     frequency="5", adjustflag="3")
# print('query_history_k_data_plus respond error_code:'+rs.error_code)
# print('query_history_k_data_plus respond  error_msg:'+rs.error_msg)
data_list = []
while (rs.error_code == '0') & rs.next():
    # 获取一条记录，将记录合并在一起
    data_list.append(rs.get_row_data())
result = pd.DataFrame(data_list, columns=rs.fields)
result.to_csv("D:\\gp\\data\\data.csv", index=False)
print(result)
bs.logout()
