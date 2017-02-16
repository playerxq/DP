// leetcode-375-猜测数字.cpp : 定义控制台应用程序的入口点。
//
/*
For each number x in range[i~j]
we do: result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}
--> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
then we get DP([i~j]) = min{xi, ... ,xj}
--> // this min makes sure that you are minimizing your cost.
*/
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		for (int j = 2; j <= n; j++)
		{
			for (int i = j - 1; i >= 1; i--)
			{
				int maxx = INT_MAX;
				for (int k = i + 1; k <= j - 1; k++)
				{
					int tmp = k + max(dp[i][k-1],dp[k+1][j]);
					maxx = min(maxx,tmp);
				}
				dp[i][j] = i + 1 == j ? i : maxx;
			}
		}
		return dp[1][n];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

