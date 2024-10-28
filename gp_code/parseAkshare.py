import akshare as ak

fund_etf_hist_em_df = ak.fund_etf_hist_em(symbol="510310", period="daily", start_date="20130101", end_date="20241027", adjust="qfq")
print(fund_etf_hist_em_df)

fund_etf_hist_em_df.to_csv("D:\\gp\\data\\510310data.csv", index=False)

