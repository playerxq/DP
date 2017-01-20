// leetcode-312-数组中最大的三个数积的和.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int sum = 1;
		if (nums.size() == 1)
			return nums[0];
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));
		int start = 0;
		int end = n;
		
		int len = 1;
		for (len = 1; len <= n; len++)
		{
			for (start = 1; start <= n-len+1; start++)
			{
				end = start + len - 1;
				int becoin = 0;
				for (int fin = start; fin <= end; fin++)
				{
					int co = rangeValues[start][fin - 1] + rangeValues[fin + 1][end];
					co += nums[start - 1] * nums[fin] * nums[end+1];
					if (co > becoin)
						becoin = co;
				}
				rangeValues[start][end] = becoin;
			}
		}

		return rangeValues[1][n];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(3);
	ve.push_back(1);
	ve.push_back(5);
	ve.push_back(8);
	Solution s;
	s.maxCoins(ve);
	return 0;
}

