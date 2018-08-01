// leetcode-877-²©ÞÄ.cpp : Defines the entry point for the console application.
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
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			dp[i][i] = piles[i];
		for (int len = 1; len <= n; len++)
		{
			for (int i = 0; i + len <= n; i++)
			{
				int j = i + len - 1;
				if (i == j)
					continue;
				dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
			}
		}
		return dp[0][n - 1] > 0;
	}
};
int main()
{
    return 0;
}

