// leetcode-650-ÊýÁÐÀ©±¶.cpp : Defines the entry point for the console application.
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
	int minSteps(int n) {
		if (n == 1) return 0;
		vector<int> dp(n + 1, 0);
		dp[2] = 2;
		return helper(dp, n);
	}
private:
	int helper(vector<int>& dp, int k) {
		if (dp[k]) return dp[k];
		int ans = k;
		for (int i = 2; i <= sqrt(k); i++) {
			if (k%i == 0) {
				ans = min(ans, helper(dp, i) + k / i);
				ans = min(ans, helper(dp, k / i) + i);
			}
		}
		dp[k] = ans;
		return ans;
	}
};
int main()
{
    return 0;
}

