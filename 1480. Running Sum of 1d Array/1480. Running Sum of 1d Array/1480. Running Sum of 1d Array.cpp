// 1480. Running Sum of 1d Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/

#include <iostream>
#include <vector> 
using namespace std;
vector<int> runningSum(vector<int>& nums);
int main()
{
    vector<int> nums = { 3,1,2,10,1 };
    nums = runningSum(nums);
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    
}

vector<int> runningSum(vector<int>& nums) {
    vector<int> result(nums.size(),0);
    result[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result[i] = result[i-1] + nums[i];
    }
    return result;
}