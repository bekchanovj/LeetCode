//922. Sort Array By Parity II
/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
vector<int> sortArrayByParityII(vector<int>& A);
int main()
{
	vector<int> A = { 3,4 };
	A = sortArrayByParityII(A);
	for (int i = 0; i < A.size(); i++) {
		cout << A[i];
	}
}

vector<int> sortArrayByParityII(vector<int>& A) {
	
	int even = 0;
	int odd = 1;
	while (true) {		
		while (even < A.size()) {
			if ((A[even] & 1) != 0)
				break;
			even += 2;
		}
		while (odd < A.size()) {
			if ((A[odd] & 1) == 0)
				break;
			odd += 2;
		}
		if (even > ((int)A.size() - 2) || odd > ((int)A.size() - 1))
			break;
		swap(A[even], A[odd]);

	}
	return move(A);
}


/*
 vector<int> sortArrayByParityII(vector<int>& A) {
   vector<int> result(A.size(),0);
	int even = 0;
	int odd = 1;
	for (int i = 0; i < A.size(); i++) {
		if ((A[i] & 1) == 0) {
			result[even] = A[i];
			even += 2;
		}
		else {
			result[odd] = A[i];
			odd += 2;
		}
	}
	return result;
	}
*/