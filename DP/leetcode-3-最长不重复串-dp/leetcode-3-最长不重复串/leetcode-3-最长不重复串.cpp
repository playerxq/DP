// leetcode-3-最长不重复串.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s=="")
			return -1;
		int len = s.length();
		if(len==0)
			return -1;
		int maxx = -1;
		int* dp = new int[len];
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<len;i++)
		{
			int id = -1;
			for(int k = i-1;k>=0&&k>=dp[i-1];k--)
			{
				if(s[k]==s[i])
				{
					id = k+1;
					break;
				}
			}
			if(id==-1)
				id = dp[i-1];
			dp[i] = id;
		}
		for(int i = 0;i<len;i++)
		{
			if(i-dp[i]+1>maxx)
				maxx = i-dp[i]+1;
		}
		return maxx;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	string str;
	getline(cin,str);
	Solution s;
	int res = s.lengthOfLongestSubstring(str);
	printf("%d",res);
}

