//258. Add Digits
/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int addDigits(int num);
//int sumNums(int num);
int main()
{
	int num = 38;
	cout << addDigits(num);
}

int addDigits(int num) {
	if (num == 0)
		return 0;
	if ((num % 9) == 0)
		return 9;
	else
		return num % 9;
}

/*
int addDigits(int num) {
	while (num >= 10) {
		num = sumNums(num);
	}
	return num % 10;
}

int sumNums(int num) {
	int temp = 0;
	while (num > 0) {
		temp += num % 10;
		num = num / 10;
	}
	return temp;
}
*/

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
