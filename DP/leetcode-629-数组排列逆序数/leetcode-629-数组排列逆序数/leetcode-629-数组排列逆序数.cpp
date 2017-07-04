// leetcode-629-数组排列逆序数.cpp : Defines the entry point for the console application.
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
	int kInversePairs(int n, int k) {
		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = 1;
			for (int j = 1; j <= k; ++j) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
				if (j - i >= 0) {
					dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
				}
			}
		}
		return dp[n][k];
	}
private:
	const int mod = pow(10, 9) + 7;
};
int main()
{
    return 0;
}

