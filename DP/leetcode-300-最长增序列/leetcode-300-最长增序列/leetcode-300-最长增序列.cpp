// leetcode-300-最长增序列.cpp : 定义控制台应用程序的入口点。
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
	int Binary_Search(int* B, int low, int high, int num)
	{
		while (low <= high) {
			int mid = (low + high) / 2;
			if (B[mid] == num)
				return mid;
			if (B[mid] > num) {
				high = mid - 1;
			}
			else {
				low = mid+1;
			}
		}
		return low;
	}
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		int* B = new int[n + 1];
		if (nums.size() == 0)
			return 0;
		B[0] = nums[0];
		int len = 1;
		for (int i = 1; i<n; i++)
		{
			if (B[len - 1]<nums[i])
				B[len++] = nums[i];
			else
			{
				int pos = Binary_Search(B, 0, len-1, nums[i]);
				B[pos] = min(B[pos], nums[i]);
			}
		}
		return len;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(10);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(8);
	nums.push_back(9);
	//nums.push_back(101);
	//nums.push_back(18);
	Solution s;
	s.lengthOfLIS(nums);
	return 0;
}

