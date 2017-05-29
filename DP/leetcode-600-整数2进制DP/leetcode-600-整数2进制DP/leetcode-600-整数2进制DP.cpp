// leetcode-600-整数2进制DP.cpp : 定义控制台应用程序的入口点。
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
	int dp[32][2];
	void init()
	{
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i <= 31; i++)
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
	}
	int dfs(int len, int num)
	{
		if (len <= 0)
			return 1;
		int val = 1 << (len - 1);
		if (num >= val)
			return dp[len - 1][0] + dfs(len - 2, num - val);
		else
			return dfs(len - 1, num);
	}
	int findIntegers(int num) {
		init();
		int len = 0;
		int n = num;
		while (n)
		{
			len++;
			n >>= 1;
		}

		return dfs(len, num);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

