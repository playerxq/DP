// leetcode-135-线性DP.cpp : 定义控制台应用程序的入口点。
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
	int calc(int n)
	{
		return n*(n+1)/2;
	}
    int candy(vector<int>& ratings) {
		if(ratings.size()<2)
			return ratings.size();
		int ans = 0;
		int up = 0;
		int down = 0;
		int oldsign = 0;
		int newsign = 0;
		for(int i = 1;i<ratings.size();i++)
		{
			if(ratings[i]>ratings[i-1])
				newsign = 1;
			else if(ratings[i]<ratings[i-1])
				newsign = -1;
			else
				newsign = 0;
			if((oldsign<0&&newsign>=0)||(oldsign>0&&newsign==0))
			{
				ans+=calc(up)+calc(down)+max(up,down);
				up = 0;
				down = 0;
			}
			if(newsign>0)
				up++;
			else if(newsign<0)
				down++;
			else
			{
				ans++;
			}
			oldsign = newsign;
		}
		ans+=calc(up)+calc(down)+max(up,down)+1;
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(2);
	ve.push_back(3);
	ve.push_back(4);
	ve.push_back(4);
	s.candy(ve);
}

