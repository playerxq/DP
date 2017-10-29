// leetcode-718-LCS.cpp : Defines the entry point for the console application.
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
	int findLength(vector<int>& A, vector<int>& B) {
		int m = A.size(), n = B.size();
		vector<int> dp(n + 1, 0); int r = 0;
		for (int i = 1; i <= m; i++)
		{
			vector<int> now(n + 1, 0);
			for (int j = 1; j <= n; j++)
			{
				if (A[i - 1] == B[j - 1])
					now[j] = dp[j - 1] + 1, r = max(r, now[j]);
			}
			dp = now;
		}
		return r;
	}
};

int main()
{
    return 0;
}

