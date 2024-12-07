import akshare as ak

fund_etf_hist_em_df = ak.fund_etf_hist_em(symbol="515180", period="daily", start_date="20130101", adjust="")
print(fund_etf_hist_em_df)

fund_etf_hist_em_df.to_csv("D:\\gp\\data\\515180data.csv", index=False)

