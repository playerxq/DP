// leetcode-741-棋牌dp.cpp : Defines the entry point for the console application.
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
	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size();
		int maxx = 2 * (n-1);
		vector<vector<int>> dp(n,vector<int>(n,-1));//dp[i][j]为两个方向各走i和j步的最大值 -1为不可达
		dp[0][0] = grid[0][0];
		for (int k = 1; k <= maxx; k++)
		{
			vector<vector<int>> curr(n, vector<int>(n, -1));
			for (int i = 0; i < n && i <= k; i++)
			{
				for (int j = 0; j < n && j <= k; j++)
				{
					if (grid[i][k - i] < 0 || grid[j][k - j] < 0) 
					{ // keep away from thorns
						continue;
					}
					int cherries = dp[i][j];
					//(i,k-i)经过终点到(j,k-j)是否可达
					if (i > 0) cherries = std::max(cherries, dp[i - 1][j]);
					if (j > 0) cherries = std::max(cherries, dp[i][j - 1]);
					if (i > 0 && j > 0) cherries = std::max(cherries, dp[i - 1][j - 1]);
					if (cherries < 0) continue;
					cherries += grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
					curr[i][j] = cherries;
				}
			}
			dp = std::move(curr);
		}
		return max(dp[n - 1][n - 1], 0);
	}
};

int main()
{
    return 0;
}

