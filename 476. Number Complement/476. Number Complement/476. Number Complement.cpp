/* 476. Number Complement
Given a positive integer num, output its complement number.The complement strategy is to flip the bits of its binary representation.
*/
#include <iostream>
#include <bitset>
int findComplement(int num);
int main()
{
    int num = 1;
    std::cout << findComplement(num);
    return 0;
}
//O(logN)

int findComplement(int num) {
    int mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    return num ^ mask;
}

/*
//Binary Search  O(logN) 
int findComplement(int num) {
    int i = 31;
    int j = 0;
    while ((i - 1) != j) {
        int mid = (i + j) / 2;
        if ((1 << mid) > num) {
            i = mid;
        }
        else {
            j = mid;
        }
    }
    return (((1 << j) + ((1 << j) - 1)) ^ num);
}
/*int findComplement(int num) {
    long int x = 1;
    while (x <= num)
    {
        x *= 2;
    }
    return x - 1 - num;
}

// Power
/*int findComplement(int num) {
    long int x = 1;
    while (x <= num)
    {
        x *= 2;
    }
    return x - 1 - num;
}
/*Mask 
    int findComplement(int num) {
    int findComplement(int num) {
        int temp = num;
        int mask = 0;
        while (num != 0) {
            num = num>>1;
            mask = mask<<1;
            mask = mask | 1;
        }
        return mask^temp;
    }
}
*/
