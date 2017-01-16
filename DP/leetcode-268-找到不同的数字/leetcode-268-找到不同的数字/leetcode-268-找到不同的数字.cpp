// leetcode-268-找到不同的数字.cpp : 定义控制台应用程序的入口点。
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
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		int maxx = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (nums[i] > maxx)
				maxx = nums[i];
		}
		if (nums.size() == maxx + 1)
			return maxx + 1;
		return (maxx)*(maxx + 1) / 2 - sum;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

