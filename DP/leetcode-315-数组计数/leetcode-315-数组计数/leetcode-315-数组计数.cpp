// leetcode-315-数组计数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n,0);
		if (n == 0)
			return res;
		int* le = new int[n];
		int* ri = new int[n];
		int* cnt = new int[n];
		for (int i = 0; i < n; i++)
		{
			le[i] = ri[i] = -1;
			cnt[i] = 0;
		}
		int cur = n-1;
		int pre = -1;
		int flag = 0;
		for (int i = n-2; i >=0; i--)
		{
			cur = n-1;
			pre = -1;
			flag = 0;
			while (cur != -1)
			{
				pre = cur;
				if (nums[i] <= nums[cur])
				{
					cnt[cur]++;
					cur = le[cur];
				}
				else
				{
					res[i] += cnt[cur];
					res[i] += 1;
					cur = ri[cur];
				}
			}
			if (nums[i] <= nums[pre])
				le[pre] = i;
			else
				ri[pre] = i;
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

