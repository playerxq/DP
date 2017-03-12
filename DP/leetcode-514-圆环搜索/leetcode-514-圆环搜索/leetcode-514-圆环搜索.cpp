// leetcode-514-圆环搜索.cpp : 定义控制台应用程序的入口点。
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
	int findRotateSteps(string ring, string key) {
		int rsize = ring.size();
		int ksize = key.size();
		vector<int> tmp(1,0);
		vector<vector<int>> dp(ksize+1,vector<int>(rsize+1,INT_MAX));
		for (int i = 0; i < rsize; i++)
			dp[0][i] = 0;
		unordered_map<char, vector<int>> mm;
		for (int i = 0; i < rsize; i++)
			mm[ring[i]].push_back(i);
		int res = INT_MAX;
		for (int i = 1; i <= ksize; i++)
		{
			for (int j = 0; j < mm[key[i - 1]].size(); j++)
			{
				for (int k = 0; k < tmp.size(); k++)
				{
					int mmm = min((mm[key[i - 1]][j] - tmp[k] + rsize) % rsize, (tmp[k] - mm[key[i - 1]][j] +rsize) % rsize)+dp[i-1][tmp[k]];
					dp[i][mm[key[i - 1]][j]] = min(dp[i][mm[key[i - 1]][j]], mmm);
					if (i == ksize)
					{
						res = min(res, dp[i][mm[key[i - 1]][j]]);
					}
				}
			}
			tmp = mm[key[i - 1]];
		}
		return res+ksize;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

