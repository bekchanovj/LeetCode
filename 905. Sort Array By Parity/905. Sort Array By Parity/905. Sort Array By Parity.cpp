//905. Sort Array By Parity
/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
using namespace std;
vector<int> sortArrayByParity(vector<int>& A);
int main()
{
    vector<int> A = { 3,1,2,4 };
    A = sortArrayByParity(A);
    for ( int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
}

// QuickSort style
vector<int> sortArrayByParity(vector<int>& A) {
    int i = 0, j = A.size()-1;
    while (i <= j) {
        if (A[i] % 2 != 0 && A[j] % 2 == 0) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
        else if (A[i] % 2 == 0) {
            i++;
        }
        else {
            j--;
        }
    }
    
    return move(A);
}


/* Brute Force
vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> result(A.size(),0);
    result.reserve(A.size());
    int index = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            result[index] = A[i];
            index++;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 != 0) {
            result[index] = A[i];
            index++;
        }
    }
    return result;
}
*/
