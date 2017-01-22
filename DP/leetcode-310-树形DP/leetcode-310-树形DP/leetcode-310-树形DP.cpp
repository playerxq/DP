// leetcode-310-树形DP.cpp : 定义控制台应用程序的入口点。
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
class Solution {
public:
	void dfs(int u, int parent, vector<vector<int>>& e, vector<int>& height1, vector<int>& height2)
	{
		height1[u] = height2[u] = -INT_MIN / 10;
		int sz = e[u].size();
		for (int i = 0; i < sz; i++)
		{
			if (e[u][i] != parent)
			{
				dfs(e[u][i], u, e, height1, height2);
				int tmp = height1[e[u][i]] + 1;
				if (tmp > height1[u])
				{
					height2[u] = height1[u];
					height1[u] = tmp;
				}
				else if (tmp > height2[u])
					height2[u] = tmp;
			}
		}
		height1[u] = max(height1[u],0);
	}
	void dfs_t(int u, int parent, int acc, vector<int>& dp,vector<vector<int>>& e, vector<int>& height1, vector<int>& height2)
	{
		dp[u] = max(height1[u],acc);
		for (int i = 0; i < e[u].size(); i++)
		{
			if (e[u][i] != parent)
			{
				int newacc = max(acc+1,(height1[e[u][i]]+1==height1[u]?height2[u]:height1[u])+1);
				dfs_t(e[u][i], u, newacc, dp, e, height1, height2);
			}
		}
	}
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		if (n<=0)
			return res;
		if (n == 1)
		{
			res.push_back(0);
			return res;
		}
		vector<vector<int>> e(n+1);
		for (int i = 0; i < edges.size(); i++)
		{
			e[edges[i].first].push_back(edges[i].second);
			e[edges[i].second].push_back(edges[i].first);
		}
		vector<int> dp(n+1,0);
		vector<int> height1(n+1,0);
		vector<int> height2(n+1,0);
		dfs(0, -1, e, height1, height2);
		dfs_t(0,-1,0,dp,e,height1,height2);
		int minx = dp[0];
		for (int i = 1; i < n; i++)
		{
			if (dp[i] < minx)
			{
				minx = dp[i];
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			if (dp[i] == minx)
				res.push_back(i);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<pair<int, int>> ve;
	ve.push_back(make_pair(1,0));
	ve.push_back(make_pair(1, 2));
	ve.push_back(make_pair(1, 3));
	Solution s;
	s.findMinHeightTrees(4,ve);
	return 0;
}

