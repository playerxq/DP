// leetcode-552-线性DP.cpp : 定义控制台应用程序的入口点。
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
	int add(int a, int b){
		return (a % 1000000007 + b % 1000000007) % 1000000007;
	}
	int checkRecord(int n) {
		vector<int> dp(n + 1, 0);
		if (n == 0)
			return 0;
		if (n == 1)
			return 3;
		if (n == 2)
			return 8;
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 4;
		for (int i = 3; i <= n; i++)
			dp[i] = add(add(dp[i - 1], dp[i - 2]), dp[i - 3]);
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res = add(res, ((long long)dp[i - 1] * dp[n - i]) % 1000000007);
		}
		res = add(res, dp[n]);
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	FILE* stream;
	//freopen("input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	//freopen("output.txt", "w", stdout);
	Solution s;
	s.checkRecord(100);
	return 0;
}

