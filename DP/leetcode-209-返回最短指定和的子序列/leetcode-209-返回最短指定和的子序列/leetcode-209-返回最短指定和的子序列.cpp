// leetcode-209-返回最短指定和的子序列.cpp : 定义控制台应用程序的入口点。
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
		if(!len)
			return 0;
		int* sum = new int[len+1];
		int* st = new int[len+1];
		int* ll = new int[len+1];
		sum[0] = nums[0];
		st[0] = 0;
		int minx = len+1;
		int id = -1;
		if(sum[0]>=s)
		{
			ll[0] = 1;
			minx = 1;
			id = 0;
		}
		for(int i = 1;i<len;i++)
		{
			if(sum[i-1]+nums[i]<=s)
			{
				st[i] = st[i-1];
				sum[i] = sum[i-1]+nums[i];
				if(sum[i]==s)
				{
					ll[i] = i-st[i]+1;
					if(ll[i]<=minx)
					{
						minx = ll[i];
						id = i;
					}
				}
			}
			else
			{
				int k = st[i-1];
				int ss = sum[i-1]+nums[i];
				while(ss-nums[k]>=s)
				{
					ss-=nums[k++];
				}
				st[i] = k;
				sum[i] = ss;
				ll[i] = i-st[i]+1;
				if(ll[i]<=minx)
				{
					minx = ll[i];
					id = i;
				}
			}
		}
		if(id==-1)
			return 0;
		else
		{
			return minx;
		}
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(10);
	ve.push_back(2);
	ve.push_back(3);
	//ve.push_back(2);
	//ve.push_back(4);
	//ve.push_back(3);
	Solution s;
	s.minSubArrayLen(6,ve);
}

