// leetcode-813-·Ö¸îÊý×é.cpp : Defines the entry point for the console application.
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
	double largestSumOfAverages(vector<int>& A, int K) {
		int n = A.size();
		if (!n)
			return 0;
		vector<vector<double>> dp(n,vector<double>(K+1,0));
		vector<vector<double>> sum(n,vector<double>(n,0));
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (j == i)
					sum[i][i] = A[i];
				else
					sum[i][j] = sum[i][j - 1] + A[j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			dp[i][1] = sum[0][i] / (i + 1);
			for (int j = 2; j <= min(K,i+1); j++)
			{
				for (int k = i-1; k >= max(0,j - 2); k--)
				{
					double t = sum[k + 1][i] / (i - k);
					dp[i][j] = max(dp[i][j],dp[k][j-1]+t);
				}
			}
		}
		return dp[n-1][K];
	}
};

int main()
{
	Solution s;
	vector<int> ve = {1, 2,3, 4, 5,6,7};
	int K = 4;
	double t = s.largestSumOfAverages(ve,K);
	t = 3;
    return 0;
}

