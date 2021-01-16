//868. Binary Gap
/*
Given a positive integer N,
find and return the longest distance between two consecutive 1's in the binary representation of N.
If there aren't two consecutive 1's, return 0

Note:
1 <= N <= 10^9
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int binaryGap(unsigned int N);
int main()
{
	cout << binaryGap(22);
}

int binaryGap( unsigned int N) {
	int gap = 1;

	if ((N & (N-1)) == 0)
		return 0;

	N = N | (N - 1);
	while (N & (N + 1) != 0) {
		N |= N >> 1;
		gap++;
	}
	return gap ;
}