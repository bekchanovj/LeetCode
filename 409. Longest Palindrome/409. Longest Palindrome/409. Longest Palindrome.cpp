//409. Longest Palindrome
/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int longestPalindrome(string s);
int main()
{
	string s = "abccccdd";
	cout << longestPalindrome(s);
}

int longestPalindrome(string s) {
	int letters[128] = {};
	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		letters[(int)s[i]]++;
	}
	for (int i = (int)'a'; i <= (int)'z'; i++) {
		result += letters[i] / 2;
	}
	for (int i = (int)'A'; i <= (int)'Z'; i++) {
		result += letters[i] / 2;
	}
	result = result * 2;
	if (result < s.size()) {
		result++;
	}
	return result;
}

auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
