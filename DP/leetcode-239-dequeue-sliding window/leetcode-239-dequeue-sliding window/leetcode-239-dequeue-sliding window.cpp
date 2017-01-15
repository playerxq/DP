// leetcode-239-dequeue-sliding window.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <deque>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i<nums.size(); i++) {
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(-7);
	nums.push_back(-4);
	nums.push_back(-8);
	nums.push_back(2);
	nums.push_back(-6);
	Solution s;
	s.maxSlidingWindow(nums,5);
	return 0;
}

