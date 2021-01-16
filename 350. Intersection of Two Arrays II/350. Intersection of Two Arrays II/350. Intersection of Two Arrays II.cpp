//
/*
Given two arrays, write a function to compute their intersection.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
#include <unordered_map>  
using namespace std;
int main()
{

}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	const vector<int>& a = nums1.size() < nums2.size() ? nums1 : nums2;
	const vector<int>& b = nums1.size() < nums2.size() ? nums2 : nums1;

	unordered_map<int, int> count;
	for (int i : a) {
		count[i]++;
	}
	vector<int> ans;
	for (int i : b) {
		unordered_map<int, int>::iterator it = count.find(i);
		if (it != count.end() && it->second > 0) {
			ans.push_back(i);
			count[i]--;
		}
	}
	return ans;
}

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
