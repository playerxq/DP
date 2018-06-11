// leetcode-837-21µã.cpp : Defines the entry point for the console application.
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
	double new21Game(int N, int K, int W) {
		if (K == 0 || N >= K + W) return 1.0;
		vector<double> dp(N+1);
		dp[0] = 1.0;
		double ws = 1.0;
		double res = 0.0;
		for (int i = 1; i <= N; i++)
		{
			dp[i] = ws / W;
			if (i < K)
				ws += dp[i];
			else
				res += dp[i];
			if (i - W >= 0)
				ws -= dp[i - W];
		}
		return res;
	}
};
int main()
{
    return 0;
}

