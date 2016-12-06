// leetcode-134-环形DP.cpp : 定义控制台应用程序的入口点。
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumc = 0;
		int sumg = 0;
		for(int i = 0;i<gas.size();i++)
			sumg += gas[i];
		for(int i = 0;i<cost.size();i++)
			sumc += cost[i];
		if(sumc>sumg)
			return -1;
		int n = gas.size();
		vector<int> rest(n);
		for(int i = 0;i<n;i++)
			rest[i] = gas[i]-cost[i];
		int st = 0;
		while(rest[st]<0)
		{
			st++;
			if(st>=n)
				return -1;
		}
		int cur = st+1;
		int res = rest[st];
		if(cur>=n)
			cur = 0;
		while(cur!=st)
		{
			res+=rest[cur];
			if(res<0)
			{
				res-=rest[st];
				st++;
				if(st>=n)
					return -1;
				while(rest[st]<0)
				{
					res-=rest[st];
					st++;
					if(st>=n)
						return -1;
					if(st>=cur)
					{
						cur = st+1;
						if(cur>=n)
							cur = 0;
						res = rest[st];
					}
				}
			}
			else
			{
				cur++;
				if(cur>=n)
					cur = 0;
			}
		}
		return st;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> g;
	vector<int> c;
	g.push_back(1);
	g.push_back(2);
	g.push_back(3);
	g.push_back(3);
	c.push_back(2);
	c.push_back(1);
	c.push_back(5);
	c.push_back(1);
	Solution s;
	s.canCompleteCircuit(g,c);
	return 0;
}

