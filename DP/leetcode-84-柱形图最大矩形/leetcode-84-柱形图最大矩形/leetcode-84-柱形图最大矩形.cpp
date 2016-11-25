// leetcode-84-柱形图最大矩形.cpp : 定义控制台应用程序的入口点。
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
    int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if(!n)
			return 0;
        int* l = new int[n+1];
		int* r = new int[n+1];
		for(int i = 0;i<n;i++)
		{
			l[i] = r[i] = i;
		}
		for(int i = 1;i<n;i++)
		{
			while(l[i]>0&&heights[i]<=heights[l[i]-1])
				l[i] = l[l[i]-1];
		}
		for(int i = n-2;i>=0;i--)
		{
			while(r[i]<n-1&&heights[i]<=heights[r[i]+1])
				r[i] = r[r[i]+1];
		}
		int maxx = -1;
		for(int i = 0;i<n;i++)
		{
			int mm = heights[i]*(r[i]-l[i]+1);
			if(mm>maxx)
				maxx = mm;
		}
		return maxx;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> heights;
	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(5);
	heights.push_back(6);
	heights.push_back(2);
	heights.push_back(3);
	s.largestRectangleArea(heights);
}

