//453. Minimum Moves to Equal Array Elements
/*
Given a non-empty integer array of size n,
find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int minMoves(vector<int>& nums);
int main()
{
	vector<int> nums = {1, 2, 3};
	cout << minMoves(nums);
}

int minMoves(vector<int>& nums) {
	int min = nums[0];
	int count = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < min)
			min = nums[i];
	}
	for (int i = 0; i < nums.size(); i++) {
			count += nums[i] - min;
	}
	return count;
}
auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
