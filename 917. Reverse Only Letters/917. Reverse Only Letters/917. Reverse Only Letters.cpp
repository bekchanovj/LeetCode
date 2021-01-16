//917. Reverse Only Letters
/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
string reverseOnlyLetters(string S);
int main()
{
	string S = "7_28]";
	cout << reverseOnlyLetters(S);
}

string reverseOnlyLetters(string S) {
	if (S.length() <= 1)
		return S;
	int i = 0, j = S.length() - 1;
	while (true) {
		while (!isalpha(S[i])) {
			i++;
			if(i >= S.length())
			break;
		}
		while (!isalpha(S[j])){
			j--;
			if (j < 0)
				break;
		}
		if (i >= j)
			break;
		swap(S[i], S[j]);		
		i++; j--;
	}
	return S;
}