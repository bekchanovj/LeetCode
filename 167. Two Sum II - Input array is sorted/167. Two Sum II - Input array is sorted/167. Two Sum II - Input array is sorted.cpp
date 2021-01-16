//167. Two Sum II - Input array is sorted
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);
int main()
{
	vector<int> nums = { -1, 0 };
	int target = -1;
	vector<int> result = twoSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<<" ";
	}
}

vector<int> twoSum(vector<int>& nums, int target) {
	int j = nums.size() - 1;
	for (int i = 0; i < nums.size(); i++) {
		while (j > i && (nums[i] + nums[j]) > target) {
			j--;
		}
		if (nums[j] + nums[i] == target) {
			return  { i+1, j+1 };
		}
	}
	
	throw invalid_argument("no solution");
}
/* First take (Not working with negative values)
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result(2, 0) ;
	int i = 0, j = nums.size() - 1;
	int indexMax = 0;
	if (nums[j] < target) {
		indexMax = j;
	}
	else {
		while (i != (j - 1)) {
			if (nums[i + ((j - i) / 2)] >= target) {
				j = i + ((j - i) / 2);
			}
			else {
				i = i + ((j - i) / 2);
			}
		}
		indexMax = i;
	}

	for (i = 0; i < indexMax; i++) {
		for (j = indexMax; j > i; j--) {
			if ((nums[i] + nums[j]) == target) {
				result[0] = i + 1;
				result[1] = j + 1;
				break;
			}
		}
	}
	return result;
}
*/




auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
