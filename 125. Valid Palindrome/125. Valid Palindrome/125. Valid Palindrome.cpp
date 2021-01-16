//125. Valid Palindrome
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
#include <assert.h>
using namespace std;
bool isPalindrome(string s);
bool isValidChar(char ch);
int main()
{
	string s = "A man, a plan, a canal: Panama";
	cout << isPalindrome(s);
}

bool isPalindrome(string s) {
	int i = 0, j = (int)s.length() - 1;
	if (s.length() == 0 || s.length() == 1)
		return true;
	while (true)
	{
		while (!isValidChar(s[i])) {
			i++;
			if (i >= s.length())
				break;
		}
		while (!isValidChar(s[j])) {
			j--;
			if (j < 0)
				break;
		}
		if (i >= j)
			return true;
		if (tolower(s[i]) != tolower(s[j])) {
			return false;
		}			
		
		i++;
		j--;
	} 
}

bool isValidChar(char ch) {
	return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'));
}