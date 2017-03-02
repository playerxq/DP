// leetcode-413-查找等差数列.cpp : 定义控制台应用程序的入口点。
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
class Solution1 {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n < 3)
			return 0;
		vector<int> dp(n,0);
		dp[0] = dp[1] = 0;
		if (A[2] - A[1] == A[1] - A[0])
			dp[2] = 1;
		for (int i = 3; i < n; i++)
		{
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				dp[i] += ((dp[i - 1]) + 1);
		}
		int sum = 0;
		for (int i = 2; i < n; i++)
			sum += dp[i];
		return sum;
	}
};
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		vector<map<int, int>> dp(n);
		
		if (!n)
			return 0;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if ((long)A[i] - (long)A[j]<INT_MIN || (long)A[i] - (long)A[j]>INT_MAX)
					continue;
				int diff = A[i] - A[j];
				dp[i][diff]++;
				if (dp[j][diff])
				{
					dp[i][diff] += dp[j][diff];
					res += dp[j][diff];
				}
			}
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(2);
	ve.push_back(3);
	ve.push_back(4);
	Solution s;
	s.numberOfArithmeticSlices(ve);
	return 0;
}

