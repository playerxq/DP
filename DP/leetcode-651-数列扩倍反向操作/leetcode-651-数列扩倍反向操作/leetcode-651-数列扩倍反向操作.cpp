// leetcode-651-数列扩倍反向操作.cpp : Defines the entry point for the console application.
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
	int maxA(int N) {
		vector<int> dp(N+1,0);
		if (N <= 6)
			return N;
		for (int i = 1; i <= 6; i++)
			dp[i] = i;
		for (int i = 7; i <= N; i++)
		{
			for (int j = 3; j <= 6; j++)
				dp[i] = max(dp[i],dp[i-j]*(j-1));
		}
		return dp[N];
	}
};
int main()
{
    return 0;
}

