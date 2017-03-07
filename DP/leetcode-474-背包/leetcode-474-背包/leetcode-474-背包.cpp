// leetcode-474-背包.cpp : 定义控制台应用程序的入口点。
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
	int findMaxForm(vector<string>& strs, int m, int n) {
		int nn = strs.size();
		if (nn == 0)
			return 0;
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		for (auto s : strs)
		{
			int z_cnt = 0;
			int o_cnt = 0;
			int ll = s.length();
			for (int k = 0; k < ll; k++)
			{
				if (s[k] == '1')
					o_cnt++;
				else
					z_cnt++;
			}
			for (int i = m; i >= z_cnt; i--)
			{
				for (int j = n; j >= o_cnt; j--)
				{
					dp[i][j] = max(dp[i][j],dp[i-z_cnt][j-o_cnt]+1);
				}
			}
		}
		return dp[m][n];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

