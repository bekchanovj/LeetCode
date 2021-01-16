/* 136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>
#include <vector>
int singleNumber(std::vector<int>& nums);
int main()
{
    std::vector<int> nums = { 4,1,2,1,2};
    std::cout << singleNumber(nums);
    return 0;
}
//General case using mod
int singleNumber(std::vector<int>& nums) {
    const int MAX_BITS= sizeof(int) * 8;
    unsigned int countOnes[MAX_BITS] = {};
    for (unsigned int i = 0; i < nums.size(); i++) {
        for (int bit = 0; bit < MAX_BITS; bit++) {
            countOnes[bit] += nums[i] & 1;
            nums[i] >>= 1;
        }
    }
    unsigned int result = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        result |= ((unsigned int)(countOnes[i] % 2) << i);
    }
    return result;
}

/* First take
int singleNumber(std::vector<int>& nums) {
    std::vector<int>::iterator it = nums.begin()+1;
    for (it; it != nums.end(); ++it) {
        nums[0] = nums[0]^(*it);
    }
    return nums[0];
}
*/
