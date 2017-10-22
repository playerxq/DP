// leetcode-713-子数组求积.cpp : Defines the entry point for the console application.
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
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int n = nums.size();
		int cnt = 0;
		vector<vector<int>> pre(n + 1, {1});//每个数字前面的积
		for (int i = 0; i < n; i++)
		{
			for (auto x : pre[i])
			{
				if (x*nums[i] < k)
				{
					cnt++;
					pre[i + 1].push_back((x*nums[i]));
				}
			}
		}
		return cnt;
	}
};

int main()
{
    return 0;
}

