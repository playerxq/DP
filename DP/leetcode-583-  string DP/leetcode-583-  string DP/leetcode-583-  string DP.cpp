// leetcode-583-  string DP.cpp : 定义控制台应用程序的入口点。
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
	int minDistance(string w1, string w2) {
		if (w1.size() == 0 || w2.size() == 0) return w1.size() + w2.size();
		vector<vector<int>> dp(w1.size(), vector<int>(w2.size(), 0));
		for (int i = 0; i < w1.size(); i++)
		{
			for (int j = 0; j < w2.size(); j++)
			{
				if (i == 0 && j == 0)
				{
					if (w1[0] != w2[0])
						dp[0][0] = 2;
					else
						dp[0][0] = 0;
				}
				else if (i == 0)
				{
					if (w1[0] != w2[j])
						dp[0][j] = min(dp[0][j - 1] + 1, 2 + j);
					else
						dp[0][j] = min(dp[0][j - 1] + 1, j);
				}
				else if (j == 0)
				{
					if (w1[i] != w2[0])
						dp[i][0] = min(dp[i - 1][0] + 1, 2 + i);
					else
						dp[i][0] = min(dp[i - 1][0] + 1, i);
				}
				else
				{
					if (w1[i] != w2[j])
					{
						dp[i][j] = dp[i - 1][j - 1] + 2;
					}
					else
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					dp[i][j] = min(dp[i][j], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
				}
			}
		}
		return dp[w1.size() - 1][w2.size() - 1];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

