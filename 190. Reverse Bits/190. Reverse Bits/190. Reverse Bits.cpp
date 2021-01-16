// 190. Reverse Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reverse bits of a given 32 bits unsigned integer.

#include <iostream>
#include <bitset>
uint32_t reverseBits(uint32_t n);
int main()
{

    int n = 0b00000010100101000001111010011100;
    std::cout << std::bitset<32>(reverseBits(n));
}

uint32_t reverseBits(uint32_t n) {
    uint32_t temp = 0;
    for (int i = 0; i < 31; i++) {
        temp = temp | (n & 1);
        temp <<= 1;
        n >>= 1;
    }
    temp = temp | (n & 1);
    return temp;
}