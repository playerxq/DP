// leetcode-647-回文子串个数.cpp : Defines the entry point for the console application.
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
	int countSubstrings(string s) {
		int count = 0;
		int n = s.length();
		vector<vector<int>> dp(n,vector<int>(n,0));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (s[i] == s[j] && (j - i < 3 || dp[j + 1][i - 1]))
					dp[i][j] = 1;
				if (dp[i][j])
					count++;
			}
		}
		return count;
	}
};
int main()
{
    return 0;
}

