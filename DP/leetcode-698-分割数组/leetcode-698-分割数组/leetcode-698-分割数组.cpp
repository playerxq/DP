// leetcode-698-·Ö¸îÊý×é.cpp : Defines the entry point for the console application.
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
	bool fun(vector<int>& nums, int sum)
	{
		if (sum == 0)
			return true;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				continue;
			if (nums[i] <= sum)
			{
				int tmp = nums[i];
				nums[i] = 0;
				if (fun(nums, sum - tmp))
					return true;
				nums[i] = tmp;
			}
			else
				return false;
		}
		return false;
	}
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		sort(nums.begin(), nums.end());
		reverse(nums.begin(), nums.end());
		for (int i = 0; i<nums.size(); i++) {
			sum += nums[i];
		}
		sum /= k;
		for (int i = 0; i<k; i++) {
			if (!fun(nums, sum)) {
				return false;
			}
		}
		return true;
	}
};
int main()
{
    return 0;
}

