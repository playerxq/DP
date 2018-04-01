// leetcode-810-²©ÞÄ.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool xorGame(vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int sum = nums[0];
		for (int i = 1; i < n; i++)
			sum ^= nums[i];
		if (sum == 0 || n % 2 == 0)
			return 1;
		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> ve = {1,1,2};
	int a = s.xorGame(ve);
	a = 10;
    return 0;
}

