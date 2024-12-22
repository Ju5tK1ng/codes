import akshare as ak

ids = {"510310", "515180", "512880", "518880", "513090", "159545", "513910", "513260", "159636", "159792", "159985", "513730",
       "159696", "513390", "159660", "513850", "513500", "159980"}
for id in ids:
    fund_etf_hist_em_df = ak.fund_etf_hist_em(symbol=id, period="daily", start_date="20150430", adjust="qfq")
    print(fund_etf_hist_em_df)
    fund_etf_hist_em_df.to_csv("D:\\gp\\data\\" + id + ".csv", index=False)
