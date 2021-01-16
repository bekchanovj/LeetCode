// 1431. Kids With the Greatest Number of Candies.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them.
Notice that multiple kids can have the greatest number of candies.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> kidsWithCandies(vector<int>&, int);
int main()
{
    vector<int> candies = { 12,1,12 };
    int extraCandies = 11;
    vector<bool> result = kidsWithCandies(candies, extraCandies);
    vector<bool> ::iterator it = result.begin();
    for (; it != result.end(); ++it) {
        cout << *it << ", ";
    }
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = *max_element(candies.begin(), candies.end());
    vector<bool> result(candies.size(), 0);
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies >= max)
            result[i] = true;
    }
    return result;
}