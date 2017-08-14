// leetcode-659-分割数组.cpp : Defines the entry point for the console application.
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
	bool helper(vector<int>& nums, int st, int ed)
	{
		int n = nums[ed] - nums[st] + 1;
		vector<int> mp(n, 0);
		for (int i = st, tmp = nums[st]; i <= ed; i++)
			mp[nums[i] - tmp]++;//计算每个数字的频率
		// ones is subsequences with length 1 ending with index i
		// twos is subsequences with length 2 ending with index i
		// tot  is all subsequences ending with index i
		//此时的index i相当于nums[]与tmp=nums[st]偏移，即nums的值
		//ones,twos,tot都为以i值结尾的串数
		int ones = 0, twos = 0, tot = 0;
		for (int i = 0; i < n; i++)
		{
			if (mp[i] < ones+twos)
				return false;
			twos = ones;
			ones = max(0,mp[i] - tot);//新的i优先分配给已有的len=2的串
			tot = mp[i];
		}
		return ones == 0 && twos == 0;
	}
	bool isPossible(vector<int>& nums) {
		int n = nums.size();
		int k = 0;
		for (int i = 1; i < n; i++)
		{
			if (nums[i] - nums[i - 1] > 1)
			{
				if (helper(nums, k, i - 1) == false)
					return false;
				k = i;
			}
		}
		return helper(nums,k,n-1);
	}
};

int main()
{
    return 0;
}

