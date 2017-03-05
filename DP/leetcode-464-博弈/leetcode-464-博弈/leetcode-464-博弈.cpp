// leetcode-464-博弈.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool helper(int desiredTotal, int maxChoosable, int record, unordered_map<int, bool>& dp)
	{
		if (dp.count(record))
			return dp[record];
		for (int i = 20; i >= 1; i--)
		{
			int t = 1 << i;
			if (t&record)
			{
				if (i >= desiredTotal)
				{
					dp[i] = true;
					return true;
				}
				bool s = helper(desiredTotal - i, maxChoosable, record^t, dp);
				dp[record^t] = s;
				if (s == false)
					return true;
			}
		}
		return false;
	}
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal == 0)
			return true;
		if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
			return false;

		unordered_map<int, bool> dp;
		int record = 0;
		for (int i = 0; i < maxChoosableInteger + 1; i++) {
			record = (record << 1) + 1;
		}
		return helper(desiredTotal, maxChoosableInteger, record, dp);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

