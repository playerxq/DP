// leetcode-769- ˝◊È÷ÿ≈≈1.cpp : Defines the entry point for the console application.
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
	int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size();
		if (!n)
			return 0;
		if (n == 1)
			return 1;
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = 1;
		}
		vector<vector<int>> mx(n + 1, vector<int>(n + 1, 0));
		vector<vector<int>> mi(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++)
		{
			mx[i][i] = mi[i][i] = arr[i];
			for (int j = i+1; j < n; j++)
			{
				mx[i][j] = mi[i][j] = arr[i];
				for (int k = i; k <= j; k++)
				{
					mx[i][j] = max(mx[i][j],arr[k]);
					mi[i][j] = min(mi[i][j], arr[k]);
				}
			}
		}
		for (int l = 1; l < n; l++)
		{
			for (int i = 0; i+l < n; i++)
			{
				int j = i + l;
				dp[i][j] = 1;
				for (int k = i; k < j; k++)
				{
					if (mx[i][k] < mi[k + 1][j])
						dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		return dp[0][n-1];
	}
};

int main()
{
	Solution s;
	vector<int> ve = {1,0,2,3,4};
	s.maxChunksToSorted(ve);
    return 0;
}

