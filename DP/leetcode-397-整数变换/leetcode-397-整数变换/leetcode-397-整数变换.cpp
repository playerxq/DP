// leetcode-397-整数变换.cpp : 定义控制台应用程序的入口点。
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
	unordered_map<int, int> dp;
	int dfs(unordered_map<int, int>& dp, int cur)
	{
		if (dp.count(cur)!=0)
			return dp[cur];
		if (cur %2==0)
		{
			dp[cur] = 1 + dfs(dp,cur/2);
		}
		else
		{
			dp[cur] = 2 + min(dfs(dp,cur/2),dfs(dp,cur/2+1));
		}
		return dp[cur];
	}
	int integerReplacement(int n) {
		if (n == 1)
			return 0;
		dp[0] = dp[1] = 0;
		return dfs(dp,n);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.integerReplacement(2147483647);
	return 0;
}

