/* 268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.*/

#include <iostream>
#include <vector>
int missingNumber(std::vector<int>& nums);
int main()
{
    std::vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
    std::cout << missingNumber(nums);
    return 0;
}

int missingNumber(std::vector<int>& nums) {
    int missing = nums[0] ^ 0;

    for (int i = 1; i < nums.size(); i++) {
        missing ^= nums[i] ^ i;
    }
    return missing ^ (int)nums.size();
}