// leetcode-712-字符串变形为同一个串.cpp : Defines the entry point for the console application.
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
//dp[i][j] is the cost for s1.substr(0,i) and s2.substr(0, j)
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int m = s1.size(), n = s2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int j = 1; j <= n; j++)
			dp[0][j] = dp[0][j - 1] + s2[j - 1];
		for (int i = 1; i <= m; i++)
		{
			dp[i][0] = dp[i - 1][0] + s1[i - 1];
			for (int j = 1; j <= n; j++)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
			}
		}
		return dp[m][n];
	}
};
int main()
{
    return 0;
}

