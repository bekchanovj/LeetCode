//888. Fair Candy Swap
/*
Alice and Bob have candy bars of different sizes: 
A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.
Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, 
and ans[1] is the size of the candy bar that Bob must exchange.
If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string> 
#include <unordered_set>
using namespace std;
vector<int> fairCandySwap(vector<int>& a, vector<int>& b);
int main()
{
	vector<int> a = { 1, 1 };
	vector<int> b = { 2, 2 };
	vector<int> res = fairCandySwap(a, b);
	cout << res[0] << " " << res[1];
}       


vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
	int sumA = 0, sumB = 0;
	unordered_set<int> bVal;
	for (int i = 0; i < a.size(); i++) {
		sumA += a[i];
	}
	for (int i = 0; i < b.size(); i++) {
		sumB += b[i];
		bVal.insert(b[i]);
	}
	int sumDiff = (sumA - sumB) / 2;
	for (int i = 0; i < a.size(); i++) {
		if (bVal.find(a[i] - sumDiff) != bVal.end()) {
			return vector<int> {a[i], (a[i] - sumDiff)};
		}
	}
}
/*Brute Force (Time limit)
vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
	vector<int> ans(2,0);
	int sumA = 0, sumB = 0;
	for (int i = 0; i < a.size(); i++) {
		sumA += a[i];
	}
	for (int i = 0; i < b.size(); i++) {
		sumB += b[i];
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if ((sumA - a[i] + b[j]) == (sumB - b[j] + a[i])) {
				ans[0] = a[i];
				ans[1] = b[j];
			}
		}
	}

	return ans;
}
*/
