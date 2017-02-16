// leetcode-377-dfs-求集合数目.cpp : 定义控制台应用程序的入口点。
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
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		vector<int> dp(target+1,0);
		sort(nums.begin(),nums.end());
		dp[0] = 1;
		for (int i = 1; i <=target; i++)
		{
			for (int j = nums.size() - 1; j >= 0; j--)
			{
				if (nums[j] <= i)
					dp[i] += dp[i-nums[j]];
			}
		}
		return dp[target];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

