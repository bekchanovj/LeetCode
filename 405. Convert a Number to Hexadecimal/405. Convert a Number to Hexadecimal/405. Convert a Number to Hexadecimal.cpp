/*405. Convert a Number to Hexadecimal
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; 
otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
*/
#include <iostream>
#include <string>
#include <bitset>
std::string toHex(int num);
//char numToChar(int hex);
int main()
{
    int num = 0;
    std::cout << toHex(num);
}


std::string toHex(int num) {
    std::string res;
    for (int i = 0; num && i < 8; i++) {
        int bit = num & 0xF;
        if (bit < 10)
            res = char('0' + bit) + res;
        else
            res = char('a' + bit - 10) + res;
        num >>= 4;
    }
    return res.empty() ? "0" : res;
}
/*Brute Force
std::string toHex(int num) {
    std::string result;
    int bits = 0;
    //std::cout << num << std::endl;
    if (num < 0) {
        num = num * (-1);
        num = (~num) + 1;
    }
    if (num == 0) {
        return "0";
    }
        //std::cout << std::bitset<32>(num) << std::endl;
    while (num != 0 ) {
        int pow = 1;
        int hex = 0;
        for (int i = 0; i < 4; i++) {
            if ((num & 1) == 1) {
                hex = hex + pow;
            }
            pow = pow * 2;
            num >>= 1;
            bits++;
            //std::cout << std::bitset<32>(num) << std::endl;
        }
        result += numToChar(hex);
        //std::cout << num << std::endl;
        if (bits == 32) {
            break;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

char numToChar(int hex) {
    if (hex <= 9) {
        return '0' + hex;
    }
    else {
        switch (hex) {
        case 10:
            return 'a';
            break;
        case 11:
            return 'b';
            break;
        case 12:
            return 'c';
            break;
        case 13:
            return 'd';
            break;
        case 14:
            return 'e';
            break;
        case 15:
            return 'f';
            break;
        }
    }
}
*/
