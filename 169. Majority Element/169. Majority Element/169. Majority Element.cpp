/*169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/ 

#include <iostream>
#include <vector>
int majorityElement(std::vector<int>& nums);

int main()
{
    std::vector<int> nums = { 3, 3, 4, 2, 4, 4, 2, 4 };
    std::cout << majorityElement(nums);
    return 0;
    
}

int majorityElement(std::vector<int>& nums) {
    int maj = nums[0], count = 1;
    std::vector<int>::iterator it = nums.begin() + 1;
    while (it != nums.end()) {
        if (*it == maj) {
            count++;
        }
        else if (count == 0) {
            maj = *it;
            count = 1;
        }
        else {
            count--;
        }
        it++;
    }

    return maj;
}