// leetcode-730-回文数目.cpp : Defines the entry point for the console application.
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
//dp[len][i][x]为起始i长度len且开始结束字符为x的回文数目
//If s[i] != x, then dp[len][i][x] = dp[len-1][i+1][x] (ignoring the first character in this window)
//If s[i+len-1] != x then dp[len][i][x] = dp[len-1][i+1][x] (ignoring the last character in this window)
//If both the first and last characters are x, then we need to count the number of distinct palindromes in the sub-window from i+1 to i + len -2.
class Solution {
public:
	int countPalindromicSubsequences(string s) {
		int md = 1000000007;
		int n = s.size();
		vector<vector<vector<int>>> dp(3,vector<vector<int>>(n,vector<int>(4,0)));
		for (int len = 1; len <= n; ++len)
		{
			for (int i = 0; i + len <= n; ++i)
			{
				for (int x = 0; x < 4; ++x)
				{
					int &ans = dp[2][i][x];//len
					ans = 0;
					int j = i + len - 1;
					char c = 'a' + x;
					if (len == 1) ans = s[i] == c;
					else
					{
						if (s[i] != c) ans = dp[1][i + 1][x];//len-1
						else if (s[j] != c) ans = dp[1][i][x];//len-1
						else
						{
							ans = 2;//头尾两个c各一个回文
							if (len > 2)
							{
								for (int y = 0; y < 4; ++y)
								{
									ans += dp[0][i + 1][y];//len-2
									ans %= md;
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					for (int x = 0; x < 4; ++x)
					{
						dp[i][j][x] = dp[i + 1][j][x];//len len-1整体上移为len-1 len-2
					}
				}
			}
		}
		int ret = 0;
		for (int x = 0; x < 4; ++x) ret = (ret + dp[2][0][x]) % md;
		return ret;
	}
};
int main()
{
    return 0;
}

