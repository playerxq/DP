// leetcode-688-棋盘DP.cpp : Defines the entry point for the console application.
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
//dp[k][r][c]  走到(r,c)处还剩k步后留在棋盘上的概率
class Solution {
public:
	double helper(vector<vector<vector<double>>>& dp, int N, int k, int r, int c)
	{
		if (r < 0 || r >= N || c < 0 || c >= N) return 0.0;
		// when k = 0, no more move, so it's 100% safe
		if (k == 0) return 1.0;
		if (dp[k][r][c] != -1.0) return dp[k][r][c];
		dp[k][r][c] = 0.0;
		for (int i = -2; i <= 2; i++)//下一步 8个方向
		{
			if (i == 0) continue;
			dp[k][r][c] += helper(dp, N, k - 1, r + i, c + 3 - abs(i)) + helper(dp, N, k - 1, r + i, c - (3 - abs(i)));
		}
		return dp[k][r][c];
	}
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, -1.0)));
		return helper(dp, N, K, r, c) / pow(8, K);//每一步有8个方向可以选择
	}
};
int main()
{
    return 0;
}

