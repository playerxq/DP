// leetcode-410-最大和最小.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		if (!n)
			return 0;
		vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
		vector<int> sum(n+1,0);
		sum[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			sum[i] = sum[i - 1] + nums[i];
		}
		if (m == 1)
			return sum[n - 1];
		for (int i = 0; i < n; i++)
			dp[i][1] = sum[i];
		for (int i = 2; i <= m; i++)
		{
			for (int j = i - 1; j < n; j++)
			{
				for (int k = i - 1; k <= j; k++)
				{
					dp[j][i] = min(dp[j][i],max(dp[k-1][i-1],sum[j]-sum[k-1]));
				}
			}
		}
		return dp[n-1][m];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve = {7,2,5,10,8};
	Solution s;
	s.splitArray(ve,2);
	return 0;
}

