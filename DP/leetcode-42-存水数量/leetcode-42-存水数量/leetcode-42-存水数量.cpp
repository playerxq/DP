// leetcode-42-存水数量.cpp : 定义控制台应用程序的入口点。
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
    int trap(vector<int>& height) {
		int n = height.size();
		if(!n||n==1)
			return 0;
		int max_now = -1;
		int pre = 0;
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			if(height[i]>=max_now)
			{
				max_now = height[i];
				sum+=pre;
				pre = 0;
			}
			else
			{
				pre+=(max_now-height[i]);
				int temp= i-1;
				while(temp>=0&&(height[i]>=height[temp]))
				{
					sum+=(height[i]-height[temp]);
					pre-=(height[i]-height[temp]);
					height[temp] = height[i];
					temp--;
				}	
			}
		}
		return sum;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(6);
	ve.push_back(8);
	ve.push_back(5);
	ve.push_back(0);
	ve.push_back(0);
	//ve.push_back(0);
	ve.push_back(6);
	ve.push_back(5);
	//ve.push_back(2);
	//ve.push_back(1);
	//ve.push_back(2);
	//ve.push_back(1);
	Solution s;
	s.trap(ve);
}

