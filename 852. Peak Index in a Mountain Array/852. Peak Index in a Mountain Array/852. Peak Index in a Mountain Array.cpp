//852. Peak Index in a Mountain Array
/*
Let's call an array A a mountain if the following properties hold: 

- A.length >= 3;
- There exists some 0 < i < A.length - 1 such that 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1];

Given an array that is definitely a mountain, return any i such that
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
int peakIndexInMountainArray(vector<int>& A);
int main()
{
	vector<int> A = { 3,4,5,1 };
	cout << peakIndexInMountainArray(A);
}
// O(log(n))
int peakIndexInMountainArray(vector<int>& A) {
	int left = 0, right = A.size() - 1;
	int mid = floor(left + (right - left) / 2);
	while ((right - left) > 2) {
		if (A[mid] > A[mid+1]) {
			right = mid+1;
		}
		else if (A[mid] > A[mid-1]) {
			left = mid;
		}		

		mid = (left + (right - left) / 2);
	}
	return mid;
}

/* O(n)
 int peakIndexInMountainArray(vector<int>& A) {
	   int left = 0, right = A.size() - 1;
		int mid = floor(left + (right - left) / 2);
		while ((right - left) > 2) {
		mid = (left + (right - left) / 2);
		if (A[mid] > A[mid+1]) {
			right = mid;
		}
		if (A[mid] > A[mid-1]) {
			left = mid;
		}
	}
	return mid;
	}
*/