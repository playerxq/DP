// leetcode-403-蛙跳.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, unordered_set<int>> dp = { { 0, { 0 } } };
		for (int i: stones)
		{
			for (auto it = dp[i].begin(); it != dp[i].end(); it++)
			{
				if (*it != 1)
				{
					dp[i + *it - 1].insert(*it-1);
				}
				dp[i + *it].insert(*it);
				dp[i + *it+1].insert(*it+1);
			}
		}
		return dp[stones.back()].size()>0;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

