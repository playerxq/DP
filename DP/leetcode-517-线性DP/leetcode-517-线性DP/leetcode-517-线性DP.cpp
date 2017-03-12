// leetcode-517-线性DP.cpp : 定义控制台应用程序的入口点。
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
	int findMinMoves(vector<int>& machines) {
		int n = machines.size();
		vector<int> dp(n+1,0);
		vector<int> sum(n+1,0);
		int target = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i-1]+machines[i-1];
		if (sum[n] == 0)
			return 0;
		if (sum[n]%n)
			return -1;
		target = sum[n] / n;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int L = (i)*target - sum[i];
			int R = (n - i - 1)*target - (sum[n]-sum[i+1]);
			if (L > 0 && R > 0)
				res = max(res, abs(L) + abs(R));
			else
				res = max(res,max(abs(L),abs(R)));
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

