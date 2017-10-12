// leetcode-691-×ÖÄ¸×éºÏ.cpp : Defines the entry point for the console application.
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
/*
dp[s] is the minimum stickers required for string s (-1 if impossible). Note s is sorted.
clearly, dp[""] = 0, and the problem asks for dp[target].
*/
class Solution {
public:
	int helper(vector<vector<int>>& mp, unordered_map<string, int>& dp, string target)
	{
		if (dp.count(target))
			return dp[target];
		int ans = INT_MAX;
		int n = mp.size();
		vector<int> ve(26,0);
		for (char c : target)
			ve[c - 'a']++;
		for (int i = 0; i < n; i++)
		{
			if (mp[i][target[0] - 'a'] == 0)
				continue;
			string s;
			for (int j = 0; j < 26; j++)
			{
				if (mp[i][j] < ve[j])
					s += string(ve[j]-mp[i][j], 'a' + j);
			}
			if (s.size() != target.size())
			{
				int tmp = helper(mp,dp,s);
				if (tmp != -1)
					ans = min(1+tmp,ans);
			}
		}
		dp[target] = (ans == INT_MAX ? -1 : ans);
		return dp[target];
	}
	int minStickers(vector<string>& stickers, string target) {
		int n = stickers.size();
		unordered_map<string, int> dp;
		vector<vector<int>> mp(n,vector<int>(26,0));
		for (int i = 0; i < n; i++)
		{
			for (char c : stickers[i])
				mp[i][c - 'a']++;
		}
		dp[""] = 0;
		return helper(mp,dp,target);
	}
};
int main()
{
    return 0;
}

