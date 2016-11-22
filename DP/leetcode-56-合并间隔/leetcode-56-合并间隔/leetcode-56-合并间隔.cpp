// leetcode-56-合并间隔.cpp : 定义控制台应用程序的入口点。
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
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
bool   lessmark(const   Interval&   s1,const   Interval&   s2)  
{  
	return   s1.start<s2.start;  
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		int n= intervals.size();
		if(n==0)
			return intervals;
		if(n==1)
			return intervals;
		vector<Interval> res;
		int** dp = new int* [n+1];
		for(int i = 0;i<n;i++)
		{
			dp[i] = new int[3];
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<3;j++)
				dp[i][j] = 0;
		}
		int id = 0;
		sort(intervals.begin(),intervals.end(),lessmark);
		dp[0][0] = intervals[0].start;
		dp[0][1] = intervals[0].end;
		for(int i = 1;i<n;i++)
		{
			if(intervals[i].start<=dp[id][1])
			{
				dp[id][1] = max(dp[id][1],intervals[i].end);
			}
			else
			{
				dp[id+1][0] = intervals[i].start;
				dp[id+1][1] = intervals[i].end;
				id++;
			}
		}
		for(int i = 0;i<=id;i++)
		{
			Interval in(dp[i][0],dp[i][1]);
			res.push_back(in);
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<Interval> ve;
	ve.push_back(Interval(1,3));
	ve.push_back(Interval(2,6));
	ve.push_back(Interval(8,10));
	ve.push_back(Interval(15,18));
	Solution s;
	s.merge(ve);
}

