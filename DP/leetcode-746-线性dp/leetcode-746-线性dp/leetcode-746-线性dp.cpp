// leetcode-746-ÏßÐÔdp.cpp : Defines the entry point for the console application.
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
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		if (!n)
			return 0;
		vector<int> dp(n+1,0);
		dp[0] = cost[0];
		if (n == 1)
			return dp[0];
		dp[1] = cost[1];
		for (int i = 2; i < n; i++)
		{
			dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
		}
		return min(dp[n-1],dp[n-2]);
	}
};
int main()
{
	vector<int> ve = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	Solution s;
	s.minCostClimbingStairs(ve);
    return 0;
}

