// leetcode-376-最长wiggle数列.cpp : 定义控制台应用程序的入口点。
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
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return 1;
		vector<int> dif(nums.size(),0);
		int k = 0;
		for (int i = 1; i < nums.size(); i++)
			dif[k++] = nums[i] - nums[i-1];
		int cnt = 0;
		int last_id = -1;
		for (int i = 0; i < k; i++)
		{
			if (i == 0)
			{
				if (dif[i] != 0)
				{
					cnt++;
					last_id = 0;
				}
				else
					cnt = 0;
			}
			else
			{
				if (dif[i] == 0)
					continue;
				else
				{
					if (dif[last_id] * dif[i]>0)
						last_id = i;
					else
					{
						last_id = i;
						cnt++;
					}
				}
			}
		}
		return cnt+1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

