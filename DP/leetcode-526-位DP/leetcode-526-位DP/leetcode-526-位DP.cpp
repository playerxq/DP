// leetcode-526-位DP.cpp : 定义控制台应用程序的入口点。
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
int dp[17][1 << 17];
class Solution {
public:
	int countrec(int ind, int N, int mask){
		if (dp[ind][mask] != -1)
			return dp[ind][mask];
		dp[ind][mask] = 0;
		if (mask == 0)
			dp[ind][mask] = 1;
		else
		{
			for (int i = 1; i <= N; i++)
			{
				if (mask&(1 << (i - 1)))
				{
					if (ind%i == 0 || i%ind == 0)
					{
						dp[ind][mask] += countrec(ind + 1, N, mask - (1 << (i - 1)));
					}
				}
			}
		}
		return dp[ind][mask];
	}
	int countArrangement(int N) {
		memset(dp, -1, sizeof(dp));
		return countrec(1, N, (1 << N) - 1);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.countArrangement(2);
	return 0;
}

