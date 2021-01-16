//
/*

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   

using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
	vector<int> prices = {0,1,4,5,6,7,8,12,14};
	
	cout << maxProfit(prices) ;
}

int maxProfit(vector<int>& prices) {
	int min1 = prices[1];
	int max1 = 0;
	for (auto it : prices) {
		max1 = max(it-min1, max1);
		min1 = min(min1, it);
	}
	return max1;
}

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
