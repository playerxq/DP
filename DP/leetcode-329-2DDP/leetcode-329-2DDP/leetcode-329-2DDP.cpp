// leetcode-329-2DDP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
class Solution {
public:
	
	int m;
	int n;
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y)
	{
		if (dp[x][y])
			return dp[x][y];
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx < 0 || xx >= m || yy < 0 || yy >= n)
				continue;
			if (matrix[xx][yy] <= matrix[x][y])
				continue;
			dp[x][y] = max(dp[x][y],dfs(matrix,dp,xx,yy));
		}
		return ++dp[x][y];
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		if (m == 0)
			return 0;
		n = matrix[0].size();
		vector<vector<int>> dp(m,vector<int>(n,0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = dfs(matrix,dp,i,j);
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = max(ans,dp[i][j]);
			}
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

