// leetcode-330-增加数组元素构成连续和.cpp : 定义控制台应用程序的入口点。
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
	int minPatches(vector<int>& nums, int n) {
		int ans = 0;
		if (n == 1)
		{
			if (nums.size() == 0||nums[0]!=1)
				return 1;
			return 0;
		}
		int top = 1;
		int st = 0;
		int id = -1;
		int len = nums.size();
		while (top <= n&&id<len)
		{
			if (top == st)
			{
				top = 2 * top;
				if (id < len-1)
					st = nums[++id];
				else
				{
					id++;
					break;
				}
			}
			else if (top < st)
			{
				ans++;
				top = 2 * top;
			}
			else
			{
				top = st + top;
				if (id < len - 1)
				{
					st = nums[++id];
				}
				else
				{
					id++;
					break;
				}
			}
		}
		if(top <= n)
		{
			ans += log2((n/top));
			ans += 1;
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> ve;
	//ve.push_back(1);
	//ve.push_back(3);
	//ve.push_back(31);
	//ve.push_back(33);
	s.minPatches(ve,8);
	return 0;
}

