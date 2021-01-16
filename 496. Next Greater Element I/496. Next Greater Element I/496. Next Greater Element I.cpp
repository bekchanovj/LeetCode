//496. Next Greater Element I
/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.

Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>   
#include <stack>   
#include <unordered_map>
#include <deque>
using namespace std;
vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2);
int main()
{
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    vector<int> test = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < nums1.size(); i++) {
        cout << test[i] << " ";
    }
}

vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> res((int)nums1.size());
    stack<int, vector<int>> greaters;
    unordered_map<int, int> numsForRes;
    for (int i = (int)nums2.size() - 1; i >= 0; i--) {
        while (!greaters.empty() && greaters.top() < nums2[i]) {
            greaters.pop();
        }
        if (greaters.empty()) {
            numsForRes[nums2[i]] = -1;
        }
        else {
            numsForRes[nums2[i]] = greaters.top();
        }
        greaters.push(nums2[i]);
    }
    for (int i = 0; i < (int)nums1.size(); i++) {
        res[i] = numsForRes[nums1[i]];
    }
    return res;
}



/* First take ~O(size1 * size2)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size(), -1);

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] == nums1[i]) {
                for (int k = j ; k < nums2.size(); k++) {
                    if (nums2[k] > nums1[i]) {
                        result[i] = nums2[k];
                        break;
                    }
                }
            }
        }
    }
    return result;
}
*/
