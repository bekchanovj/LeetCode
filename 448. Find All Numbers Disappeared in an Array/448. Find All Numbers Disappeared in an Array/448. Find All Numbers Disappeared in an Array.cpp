//
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums);
int main()
{
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> result = findDisappearedNumbers(nums);
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
		cout << *it << " ";
	}
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> result;
	for (int i = 0; i < (int)nums.size(); i++) {
		while (true) {
			int j = nums[i] - 1;
			if (nums[i] == nums[j]) {
				break;
			}
			swap(nums[i], nums[j]);
		}
		
	}
	for (int i = 0; i < (int)nums.size(); i++) {
		if (nums[i] != i + 1) {
			result.push_back(i+1);
		}
	}
	return result;
}

/*
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> result;
	for (int i = 0; i < (int)nums.size(); i++) {
		if (nums[abs(nums[i]) -1] > 0) {
			nums[abs(nums[i]) - 1] *= -1;
		}
	}
	for (int i = 1; i < (int)nums.size(); i++) {
		if (nums[i] > 0) {
			result.push_back(i+1);
		}
	}
	return result;
}
*/


auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
