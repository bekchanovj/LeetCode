//821. Shortest Distance to a Character
/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Note:
S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   

using namespace std;
vector<int> shortestToChar(string s, char c);
int main()
{
	string s = "loveleetcode";
	char c = 'e';
	vector<int> result = shortestToChar(s, c);
	for (int i = 0; i < s.length(); i++) {
		cout << result[i];
	}
}

vector<int> shortestToChar(string s, char c) {

	int prePos = 0;
	vector<int> result((int)s.length(), 0);

	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == c) {
			for (int j = i - 1; j >= 0; j--) {
				result[j] = abs(j-i);
			}
			prePos = i;
			break;
		}		
	}	
	int k = 0;
	for (int i = prePos; i < (int)s.length(); i++) {
		if (s[i] == c) {
			if (i - prePos == 1) {
				prePos = i;
			}
			else {
				k = i - 1;
				for (int j = prePos + 1	 ; j <= k; j++, k--) {
					result[j] = j-prePos;
					result[k] = i - k;
				}
				prePos = i;
			}			
		} 
	}
		for (int i = prePos + 1; i < s.length(); i++) {
			result[i] = i-prePos;
		}		
	return result;
}

/*2nd take
vector<int> shortestToChar(string s, char c) {
	const int INF = (int)s.size();
	int dst = INF;
	vector<int> result(s.length(), INF);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			dst = 0;
		}
		else {
			dst++;
		}
		result[i] = dst;
	}
	dst = INF;
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == c) {
			dst = 0;
		}
		else {
			dst++;
		}
		if(dst<result[i])
		result[i] = dst;
	}
	return result;
}
*/

/*1st take
vector<int> shortestToChar(string s, char c) {
	vector<int> result(s.length(), 0);
	int right,left;
	for(int i = 0; i < (int)s.length(); i++) {
		if (s[i] == c) {
			right = i;
			break;
		}
	}
	for (int i = (int)s.length()-1; i >= right ; i--) {
		if (s[i] == c) {
			left = i;
			break;
		}
	}
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == c) {
			right = i;
			result[i] = 0;
		}
		else {
			result[i] = abs(right-i);
		}
	}
	for (int i = (int)s.length()-1; i >=0; i--) {
		if (s[i] == c) {
			left = i;
		}
		else {
			if (abs(left - i) < result[i]) {
				result[i] = abs(left - i);
			}
		}
	}
	return result;
}
*/
