#include<bits/stdc++.h>
using namespace std;
int getValue(vector<int> gifts, int n) {
    map<int, int> cnt;
    for (int i = 0; i < gifts.size(); i++)
    {
    	cnt[gifts[i]]++;
    	if (cnt[gifts[i]] > n / 2)
    	{
    		return gifts[i];
		}
	}
	return 0;
}
int main()
{
	int n, t;
	cin >> n;
	vector<int> gifts;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		gifts.push_back(t);
	}
	cout << getValue(gifts, n) << endl;
	return 0;
}
