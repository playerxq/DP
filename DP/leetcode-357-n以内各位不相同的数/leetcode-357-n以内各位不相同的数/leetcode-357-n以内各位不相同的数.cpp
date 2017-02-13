// leetcode-357-n以内各位不相同的数.cpp : 定义控制台应用程序的入口点。
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

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 10;
		for (int i = 2; i <= n; i++){
			dp[i] = 9;
			int k = 9;
			int count = 1;
			while (count <i){
				dp[i] *= k;
				k--;
				count++;
			}
			dp[i] += dp[i - 1];
		}
		return dp[n];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

