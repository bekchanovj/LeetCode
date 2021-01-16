//283. Move Zeroes
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
void moveZeroes(vector<int>& nums);
int main()
{
	vector<int> nums = { 0,1,0,3,12};
	moveZeroes(nums);
	for (vector<int> ::iterator it = nums.begin(); it != nums.end(); ++it) {
		cout << *it <<" ";
	}
}

void moveZeroes(vector<int>& nums) {
	int indexZero = 0;
	int indexInt = 0;
	while (indexZero < (int)nums.size() && nums[indexZero] != 0) {
		indexZero++;
	}
	indexInt = indexZero;
	for (;indexInt < nums.size(); indexInt++) {
		if (nums[indexInt] != 0) {
			swap(nums[indexZero], nums[indexInt]);
			indexZero++;
		}		
	}
}

/*
void moveZeroes(vector<int>& nums) {
	int indexZero = 0;
	int indexInt = 0;
	while (int i = 0; i < nums.size(); i++) {
		indexZero = i;
		indexInt = i;
		while (indexZero < nums.size() && nums[indexZero] != 0) {
			indexZero++;
		}
		while (indexInt < nums.size() &&  indexZero < nums.size() && nums[indexInt] == 0) {
			indexInt++;
		}

		if( indexZero < nums.size() &&  indexInt < nums.size() && indexInt > indexZero)
		swap(nums[indexZero], nums[indexInt]);
		}
}

*/

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
