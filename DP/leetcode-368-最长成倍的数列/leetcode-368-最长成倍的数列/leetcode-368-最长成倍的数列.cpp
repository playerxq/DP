// leetcode-368-最长成倍的数列.cpp : 定义控制台应用程序的入口点。
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
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> res;
		if (nums.size() == 0)
			return res;
		vector<int> cnt(nums.size(),1);
		vector<int> pre(nums.size(),-1);
		if (nums.size() == 1)
		{
			res.push_back(nums[0]);
			return res;
		}
		sort(nums.begin(),nums.end());
		int maxx = 0;
		int id = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] % nums[j] == 0)
				{
					if (1 + cnt[j] > cnt[i])
					{
						cnt[i] = cnt[j] + 1;
						pre[i] = j;
					}
				}
			}
			if (cnt[i] > maxx)
			{
				id = i;
				maxx = cnt[i];
			}
		}
		while (id != -1)
		{
			res.push_back(nums[id]);
			id = pre[id];
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

