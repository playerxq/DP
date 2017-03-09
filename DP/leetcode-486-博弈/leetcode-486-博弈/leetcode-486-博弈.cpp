// leetcode-486-博弈.cpp : 定义控制台应用程序的入口点。
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
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		if (!n || n == 1)
			return true;
		vector<vector<int>> sum(n+1,vector<int>(n+1,0));
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
					sum[i][j] = nums[i];
				else
					sum[i][j] = sum[i][j - 1] + nums[j];
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
					dp[i][j] = nums[i];
				else if (i == j - 1)
				{
					dp[i][j] = max(nums[i],nums[j]);
				}
				else
				{
					dp[i][j] = max(nums[i]+sum[i+1][j]-dp[i+1][j],nums[j]+sum[i][j-1]-dp[i][j-1]);
				}
			}
		}
		return dp[0][n - 1] >= sum[0][n - 1] / 2 + sum[0][n - 1] % 2;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

