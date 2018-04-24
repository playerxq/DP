// leetcode-823-½¨¶þ²æÊ÷.cpp : Defines the entry point for the console application.
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
	int numFactoredBinaryTrees(vector<int>& A) {
		int n = A.size();
		if (!n)
			return 0;
		if (n == 1)
			return 1;
		sort(A.begin(),A.end());
		int md = (int)pow(10, 9) + 7;
		vector<long long> dp(n,1);
		for (int i = 0; i < n; i++)
		{
			for (int l = 0; l < i; l++)
			{
				for (int r = l; r < i; r++)
				{
					if (A[l] * A[r] == A[i])
					{
						if (A[l] == A[r])
						{
							int t = ((dp[l] * dp[r]) % md);
							dp[i] = (dp[i] + t) % md;
						}
						else
						{
							int t = ((2 * dp[l] * dp[r]) % md);
							dp[i] = (dp[i] + t) % md;
						}
						dp[i] %= md;
					}
					else if (A[l] * A[r] > A[i])
						break;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res += dp[i];
			res %= md;
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> ve = { 2, 4};
	s.numFactoredBinaryTrees(ve);
    return 0;
}

