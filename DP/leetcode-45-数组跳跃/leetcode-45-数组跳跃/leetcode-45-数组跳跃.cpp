// leetcode-45-数组跳跃.cpp : 定义控制台应用程序的入口点。
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
    int jump(vector<int>& nums) 
    {
        int size = nums.size();
        if(size < 2)
        {
            return 0;
        }

        vector<int> maxJump(size, 0);
        int curCount = 0;
        for(int i = 0; i < size; ++i)
        {
            if(i + nums[i] >= size - 1)
            {
                return curCount + 1;
            }
            maxJump[curCount + 1] = max(i + nums[i], maxJump[curCount + 1]);
            curCount = (i == maxJump[curCount]) ? curCount + 1 : curCount; 
        }
        
        return curCount + 1;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
		int n = nums.size();
		if(n<2)
			return 0;
		int maxsize = 0;
		int i = 0;
		int level = 0;
		int nextmax = 0;
		while(maxsize-i+1>0)
		{
			level++;
			for(;i<=maxsize;i++)
			{
				nextmax=max(nextmax,nums[i]+i);
				if(nextmax>=n-1)
					return level;
			}
			maxsize = nextmax;
		}
		return 0;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(2);
	ve.push_back(1);
	//ve.push_back(1);
	//ve.push_back(3);
	//ve.push_back(1);
	//ve.push_back(1);
	//ve.push_back(1);
	Solution s;
	s.jump(ve);
}

