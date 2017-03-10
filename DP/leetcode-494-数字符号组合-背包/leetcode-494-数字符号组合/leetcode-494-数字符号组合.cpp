// leetcode-494-数字符号组合.cpp : 定义控制台应用程序的入口点。
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
	int helper(vector<int>& nums, int s)
	{
		vector<int> dp(s+1,0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = s; j >= nums[i]; j--)
			{
				dp[j] += dp[j-nums[i]];
			}
		}
		return dp[s];
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum < S || (S + sum) % 2 == 1)
			return 0;
		return helper(nums, (S + sum) / 2);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

