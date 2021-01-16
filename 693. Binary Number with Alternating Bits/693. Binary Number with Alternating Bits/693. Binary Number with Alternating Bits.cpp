/*  693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.*/ 

#include <iostream>
bool hasAlternatingBits(int n);
int main()
{
    int n = 7;
    std::cout << hasAlternatingBits(10);
    return 0;
}


bool hasAlternatingBits(unsigned int n) {
    n ^= n >> 1;
    return ((n & (n + 1)) == 0);
}


/* 2nd take
bool hasAlternatingBits(int n) {
    if (n == 1) return true;
    int bits = floor(log2(n)) + 1;
    int tmp = pow(2, bits) - 1;
    return (n ^ (n >> 1)) == tmp ? true : false;
}

*/

    /*Brute Force
    int temp = n & 1;
    n >>= 1;
    if (n == 0 && temp == 1) {
        return true;
    }
    else if (n == 0) {
        return false;
    }
    else {
        while (n != 0) {
            if (temp == (n & 1)) {
                return false;
            }
            else {
                temp = n & 1;
            }
            n >>= 1;             
        }
    }
    return true;
}
*/