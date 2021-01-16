// 231. Power of Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Given an integer, write a function to determine if it is a power of two.
#include <iostream>
bool isPowerOfTwo(int n);
int main()
{
    int n = 0;
    std::cout << isPowerOfTwo(n);
}

bool isPowerOfTwo(int n) {
    if (n <= 0)return false;
    else return(!(n & (n - 1)));
}
/*Brute Force
bool isPowerOfTwo(int n) {
    int temp;
    if (n == 0) {
        return false;
    }
    while (n) {
        temp = n & 1;
        n >>= 1;
        if (temp == 1 && n != 0)
            return false;
    }
    return true;
}
*/
