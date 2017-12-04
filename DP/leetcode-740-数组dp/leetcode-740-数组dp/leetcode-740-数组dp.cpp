// leetcode-740-数组dp.cpp : Defines the entry point for the console application.
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
//dp[i]为第一次删除小于等于值为i的数
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<int> fre(10001, 0);
		for (int i = 0; i < n; i++)
			fre[nums[i]]++;
		vector<int> dp(10001, 0);
		dp[1] = fre[1];
		dp[2] = max(fre[1], fre[2] * 2);
		for (int i = 3; i < 10001; i++)
		{
			dp[i] = max(dp[i - 1], fre[i] * i + dp[i - 2]);
		}
		return dp[10000];
	}
};
int main()
{
    return 0;
}

