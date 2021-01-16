/* 461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.
*/
#include <iostream>
int hammingDistance(int x, int y);
int main()
{
    int x = 1, y = 4;
    std::cout << hammingDistance(x, y);
    return 0;
}

int hammingDistance(int x, int y) {
    x = x ^ y;
    int dist = 0;
    while (x > 0) {
        dist++;
        x = x & (x - 1);
    }
    return dist;
}