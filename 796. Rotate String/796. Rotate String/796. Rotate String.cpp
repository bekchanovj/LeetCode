//796. Rotate String
/*
We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. 
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. 
Return True if and only if A can become B after some number of shifts on A.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
bool rotateString(string A, string B);
int main()
{
	string A = "abcde", B = "abced";
	cout << rotateString(A, B);
}
bool rotateString(string A, string B) {
	return (A.length() == B.length()) && ((A+A).find(B) != string::npos);
}

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
