// leetcode-152-连续数字最大乘积.cpp : 定义控制台应用程序的入口点。
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
    int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int* cum = new int[n+1];
		int* cnt = new int[n+1];
		int* pre = new int[n+1];
		cum[0] = nums[0];
		int ans = INT_MIN;
		int star=-1;
		if(nums[0]<0)
		{
			pre[0]=0;
			star = 0;
		}
		for(int i = 1;i<n;i++)
		{
			if(nums[i])
			{
				if(star==-1&&nums[i]<0)
					star = i;
				if(cum[i-1])
					cum[i] = cum[i-1]*nums[i];
				else
				{
					cum[i] = nums[i];
				}
				pre[i] = star;
			}
			else
			{
				cum[i] = 0;
				star = -1;
			}
		}
		int n_cnt = 0;//当前段内负号个数
		for(int i = 0;i<n;i++)
		{
			if(nums[i]>0)
			{
				cnt[i] = n_cnt;
			}
			else if(nums[i]==0)
				n_cnt = 0;
			else
			{
				n_cnt++;
				cnt[i] = n_cnt;
			}
		}
		for(int i = 0;i<n;i++)
		{
			if(nums[i]&&cnt[i]%2==0)
			{
				ans = max(ans,cum[i]);
			}
			else if(nums[i]&&cnt[i]%2)
			{
				if(pre[i]!=i)
					ans = max(ans,cum[i]/cum[pre[i]]);
				else
					ans = max(ans,nums[i]);
			}
			else
				ans = max(ans,0);
		}
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(-2);
	nums.push_back(4);
	s.maxProduct(nums);
}

