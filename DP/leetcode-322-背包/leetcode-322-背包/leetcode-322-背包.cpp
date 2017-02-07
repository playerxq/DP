// leetcode-322-背包.cpp : 定义控制台应用程序的入口点。
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
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1,0);
		if (amount == 0)
			return 0;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i - coins[j] >= 0)
				{
					if (i - coins[j] ==0||dp[i - coins[j]])
					{
						if (dp[i] != 0)
							dp[i] = min(dp[i], dp[i - coins[j]] + 1);
						else
							dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		if (dp[amount] == 0)
			return -1;
		return dp[amount];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(2);
	ve.push_back(5);
	Solution s;
	s.coinChange(ve,11);
	return 0;
}

