/*
1486. XOR Operation in an Array

Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.
*/
#include <iostream>
int xorOperation(int n, int start);

int main()
{
    int n = 5, start = 0;
    std :: cout << xorOperation(n, start);
    return 0;
}

int xorOperation(int n, int start) {
    int temp = start;
    for (int i = 1; i < n; i++) {
        start = start ^ (temp = (temp + 2));
    }
    return start;
}