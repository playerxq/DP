// leetcode-121-122-123-股票售卖-数组序列DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
//一次交易
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
		if(!len)
			return 0;
		int minx = prices[0];
		int max_profit = 0;
		for(int i = 1;i<len;i++)
		{
			if(prices[i]>minx)
			{
				max_profit = max(max_profit,prices[i]-minx);
			}
			else
				minx = min(minx,prices[i]);
		}
		return max_profit;

    }
};
//多次非重复交易
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
		if(!len)
			return 0;
		int ans = 0;
		for(int i = 1;i<len;i++)
		{
			ans+=max(0,prices[i]-prices[i-1]);
		}
		return ans;
    }
};
//至多两次非重复交易
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
		if(!len)
			return 0;
		int ans = 0;
		int* f_min = new int[len+1];
		int* f_max = new int[len+1];
		int* b_min = new int[len+1];
		int* b_max = new int[len+1];
		int* f_pro = new int[len+1];
		int* b_pro = new int[len+1];
		for(int i = 0;i<len;i++)
			f_pro[i] = b_pro[i] = 0;
		f_min[0] = f_max[0] = prices[0];
		b_min[len-1] = b_max[len-1] = prices[len-1];
		for(int i = 1;i<len;i++)
		{
			if(prices[i]<f_min[i-1])
			{
				f_min[i] = f_max[i] = prices[i];
			}
			else if(prices[i]>f_max[i-1])
			{
				f_min[i] = f_min[i-1];
				f_max[i] = prices[i];
			}
			else
			{
				f_min[i] = f_min[i-1];
				f_max[i] = f_max[i-1];
			}
			f_pro[i] = max(f_pro[i-1],f_max[i]-f_min[i]);
		}
		for(int i = len-2;i>=0;i--)
		{
			if(prices[i]<b_min[i+1])
			{
				b_min[i] = prices[i];
				b_max[i] = b_max[i+1];
			}
			else if(prices[i]>b_max[i+1])
			{
				b_min[i] = b_max[i] = prices[i];
			}
			else
			{
				b_min[i] = b_min[i+1];
				b_max[i] = b_max[i+1];
			}
			b_pro[i] = max(b_pro[i+1],b_max[i]-b_min[i]);
		}
		for(int i = 0;i<len;i++)
		{
			if(i<len-1)
			{
				ans = max(ans,f_pro[i]+b_pro[i+1]);
			}
			else
				ans = max(ans,f_pro[i]);
		}
		return ans;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	/*
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(9);
	nums.push_back(4);
	nums.push_back(9);
	*/
	int a = s.maxProfit(nums);
	return 0;
}

