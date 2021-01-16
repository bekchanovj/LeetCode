// 338. Counting Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <iostream>
#include <vector>
std::vector<int> countBits(int num);
//int countOnes(int n);
int main()
{
     int num = 5;
     std::vector<int>::iterator it;
     std::vector<int> ones = countBits(num);
     for (it = ones.begin(); it != ones.end(); ++it) {
         std::cout << *it << " ";
     }

}

std::vector<int> countBits(int num) {
    std::vector<int> result (num+1,0);
    for (int i = 1; i <= num; i++) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}

/*Brute Force
std::vector<int> countBits(int num) {
    std::vector<int> result;
    result.reserve(num + 1);
    std::vector<int>::iterator it;
    for (int i = 0; i <= num; i++) {
        result.push_back(countOnes(i));
    }
    return result;
}


int countOnes(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

*/
