// leetcode-873-最长斐波那契子串.cpp : Defines the entry point for the console application.
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
	int lenLongestFibSubseq(vector<int>& A) {
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));//end with A[i] and A[j]
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				dp[i][j] = 2;
			}
		}
		map<int, int> mp;
		for (int i = 0; i < n; i++)
			mp[A[i]] = i;
		for (int j = 1; j < n; j++)
		{
			for (int i = j - 1; i >= 0; i--)
			{
				if (!mp.count(A[j] - A[i]))
					continue;
				if (mp[A[j] - A[i]] >= i)
					break;
				int t = mp[A[j] - A[i]];
				dp[i][j] = max(dp[i][j], dp[t][i] + 1);
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (dp[i][j] > 2)
					res = max(res,dp[i][j]);
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> ve = { 1,3,7,11,12,14,18 };
	s.lenLongestFibSubseq(ve);
    return 0;
}

