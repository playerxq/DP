// leetcode-664-×Ö·û´®ÐòÁÐDP.cpp : Defines the entry point for the console application.
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
	int dp[101][101];
	int strangePrinter(string s) {
		memset(dp, INT_MAX, sizeof(dp));
		int len = (int)s.size();
		if (len == 0) return 0;
		for (int i = 0; i < len; i++) dp[i][i] = 1;
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j + i < len; j++)
			{
				dp[j][j + i] = i + 1;
				for (int k = j + 1; k <= j + i; k++)
				{
					int temp = dp[j][k - 1] + dp[k][j + i];
					if (s[k - 1] == s[j + i])
						temp--;
					dp[j][j + i] = min(dp[j][j + i], temp);
				}
			}
		}
		return dp[0][len - 1];
	}
};
int main()
{
    return 0;
}

