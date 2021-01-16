//717. 1-bit and 2-bit Characters
/*
We have two special characters. 
The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).		

Now given a string represented by several bits. 
Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
bool isOneBitCharacter(vector<int>& bits);
int main()
{
	vector<int> bits = { 1, 0, 0 };
	cout << isOneBitCharacter(bits);
}

bool isOneBitCharacter(vector<int>& bits) {
	int count = 1;
	for (int i = bits.size() - 2; i >= 0; i--) {
		if (bits[i] == 0) {
			break;
		}
		else
			count++;
	}
	return (count % 2) == 1;
}
auto booster = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
