// leetcode-576-棋盘DP.cpp : 定义控制台应用程序的入口点。
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
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(m, vector<long long>(n, 0)));
		for (int cn = 1; cn <= N; cn++)
		{
			for (int r = 0; r < m; r++)
			{
				for (int c = 0; c < n; c++)
				{
					long long t = 0;
					t += (r == 0 ? 1 : dp[cn - 1][r - 1][c]);
					t %= 1000000007;
					t += (r == m - 1 ? 1 : dp[cn - 1][r + 1][c]);
					t %= 1000000007;
					t += (c == 0 ? 1 : dp[cn - 1][r][c - 1]);
					t %= 1000000007;
					t += (c == n - 1 ? 1 : dp[cn - 1][r][c + 1]);
					t %= 1000000007;
					dp[cn][r][c] = t;
				}
			}
		}
		return dp[N][i][j];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

