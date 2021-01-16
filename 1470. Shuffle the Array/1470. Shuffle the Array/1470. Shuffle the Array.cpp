// 1470. Shuffle the Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Constraints:
1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> shuffle(vector<int>& nums, int n);

int main(){
    vector<int> nums{ 2,5,1,3,4,7 };
    int n = 3;
    nums = shuffle(nums, n);
    vector<int>::iterator it = nums.begin();
    for (;it!=nums.end(); ++it) {
        cout << *it <<" ";
    }
    return 0;
}

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(2 * n, 0);
    int j = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        result[i] = nums[j];
        j++;
    }
    for (int i = 1; i < 2 * n; i += 2) {
        result[i] = nums[j];
        j++;
    }
    return result;
}