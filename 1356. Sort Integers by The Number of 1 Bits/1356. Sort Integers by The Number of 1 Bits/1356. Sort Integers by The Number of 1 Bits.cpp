/*1356. Sort Integers by The Number of 1 Bits
Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation 
and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.
    
*/
#include <vector>
#include <iostream>
#include <algorithm>
std::vector<int> sortByBits(std::vector<int>& arr);
bool compareInts(int, int);
int countOnes(int n);
int main()
{
    std::vector<int> arr = { 0,1,2,3,4,5,6,7,8 };
    std::vector<int> test = sortByBits(arr);
    for (std::vector<int>::iterator it = test.begin(); it != test.end();++it) {
        std::cout << *it <<"\t";
    }
    return 0;
}

std::vector < int > sortByBits(std::vector < int >& arr) {
    sort(arr.begin(), arr.end(), compareInts);
    return arr;
}

static int countOnes(int n) {
    int count = 0;
    while (n != 0) {
        n &= n - 1;
        count++;
    }
    return count;
}

static bool compareInts(int a, int b) {
    int ca = countOnes(a);
    int cb = countOnes(b);
    if (ca == cb) {
        return a < b;
    }
    else {
        return ca < cb;
    }
}

/*std::vector<int> sortByBits(std::vector<int>& arr) {
    sort(arr.begin(), arr.end(), compareInts);
    return arr;
    
    long int* temp = new long int[arr.size()];
    for (int i = 0; i < arr.size(); i++) {
        temp[i] = countOnes(arr[i]);
    }
    std::sort(temp,temp+arr.size());
    for (int i = 0; i < arr.size(); i++) {
        std::cout << temp[i]<<" ";
    }
    std::cout << std::endl;
    int buff = 1;
    int diff = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (temp[i] != temp[i -1]) {
            std::sort(arr.begin() + buff, arr.begin() + i);
            std::cout << buff << " " << i << std::endl;
            buff = i+1;
            
        }
    }
    if (temp[arr.size() - 1] != temp[arr.size() - 2]) {
        std::sort(arr.begin() + buff, arr.begin() + buff);
        std::cout << buff << " " << buff << std::endl;
    }
    delete [] temp;
    return arr;
}*/

