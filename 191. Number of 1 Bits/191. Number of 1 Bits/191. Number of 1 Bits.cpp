/* 191. Number of 1 Bits 
Write a function that takes an unsigned integerand return the number of '1' bits it has(also known as the Hamming weight).*/
#include <iostream>
int hammingWeight(uint32_t n);
int main()
{
    int n = 0b11111111111111111111111111111101;
    std::cout << hammingWeight(n);
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        count++; 
        n = n & (n - 1);
    }
    return count;
}