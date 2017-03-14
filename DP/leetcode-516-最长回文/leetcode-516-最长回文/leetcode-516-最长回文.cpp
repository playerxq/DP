// leetcode-516-最长回文.cpp : 定义控制台应用程序的入口点。
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

class Solution
{
public:
	int longestPalindromeSubseq(string s)
	{
		if (s.empty())
			return 0;
		vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
		for (int i = 1; i <= s.size(); i++)
		{
			for (int l = 0; l + i <= s.size(); l++)
			{
				int r = l + i - 1;
				if (l == r)
					dp[l][r] = 1;
				else if (l + 1 == r)
				{
					dp[l][r] = (s[l] == s[r]) ? 2 : 1;
				}
				else
				{
					int t = s[l] == s[r] ? 2 : 0;
					dp[l][r] = max(max(dp[l+1][r],dp[l][r-1]),dp[l+1][r-1]+t);
				}
			}
		}
		return dp[0][s.size()-1];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

