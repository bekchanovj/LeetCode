//696. Count Binary Substrings	
/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, 
and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int countBinarySubstrings(string s);
int main() {
	string s = "00110011";
	cout << countBinarySubstrings(s);
}

int countBinarySubstrings(string s) {
	int preSize = 0, curSize = 0;
	int count = 0;
	char curCh = '#';
	for (char c : s) {
		if (c == curCh) {
			curSize++;
		}
		else {
			count += min(preSize, curSize);
			curCh = c;
			preSize = curSize;
			curSize = 1;
		}
	}
	count += min(preSize, curSize); 
	return count;
}

/*
int countBinarySubstrings(string s) {
	int count = 0;
	int j, k = 0;
	for (int i = 0; i < (s.length()-1); i++) {
		if (s[i] != s[i + 1]) {
			j = i;
			k = i + 1;
			char temp = s[k];
			while (j >= 0 && k < s.length()) {
				if (s[j] != s[k] && (s[k] == temp)) {
					count++;
					j--;
					k++;
				}
				else
					break;
			}
		}
	}
	return count;
}
*/


auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
