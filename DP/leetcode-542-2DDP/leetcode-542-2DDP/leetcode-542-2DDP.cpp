// leetcode-542-2DDP.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int h = matrix.size();
		int w = matrix[0].size();
		vector<vector<int>> dp(h,vector<int>(w,INT_MAX));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (matrix[i][j] == 0)
					dp[i][j] = 0;
			}
		}
		int i, j;
		for (int k = 0; k < 2; k++)
		{
			for (i = ((k == 0) ? 0 : h - 1); k == 0 ? i < h : i >= 0; k == 0 ? i++ : i--)
			{
				for (j = ((k == 0) ? 0 : w - 1); k == 0 ? j < w : j >= 0; k == 0 ? j++ : j--)
				{
					if (dp[i][j])
					{
						if (i&&dp[i - 1][j] != INT_MAX&&dp[i][j] > dp[i - 1][j] + 1)
						{
							dp[i][j] = dp[i - 1][j] + 1;
						}
						if (j&&dp[i][j - 1] != INT_MAX&&dp[i][j]>dp[i][j - 1] + 1)
							dp[i][j] = dp[i][j - 1] + 1;
						if (i<h - 1 && dp[i + 1][j] != INT_MAX&&dp[i][j]>dp[i + 1][j] + 1)
							dp[i][j] = dp[i + 1][j] + 1;
						if (j<w - 1 && dp[i][j + 1] != INT_MAX&&dp[i][j]>dp[i][j + 1] + 1)
							dp[i][j] = dp[i][j + 1] + 1;
					}
				}
			}
		}
		return dp;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

