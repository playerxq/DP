// leetcode-32-最长括号匹配.cpp : 定义控制台应用程序的入口点。
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
    int longestValidParentheses(string s) {
		int n = s.size();
		int maxx = 0;
		int* dp = new int [n+1];
		int* cc = new int [n+1];
		memset(dp,0,(n+1)*sizeof(dp));
		memset(cc,0,(n+1)*sizeof(cc));
		for(int i = 1;i<n;i++)
		{
			if(s[i]=='(')
				dp[i] = i;
			else
			{
				if(s[i-1]=='(')
					dp[i] = i-1;
				else
				{
					int k = dp[i-1];
					while(k&&s[k-1]==')')
					{
						k = dp[k-1];
					}
					if(k&&s[k-1]=='(')
						dp[i] = k-1;
					else
						dp[i] = i;
				}
			}
		}
		int id=0;
		for(int i = n-1;i>=0;)
		{
			if(dp[i]!=i)
			{
				cc[id++] = i-dp[i]+1;
				i = dp[i]-1;
			}
			else
			{
				cc[id++]=0;
				i--;
			}
		}
		int sum = 0;
		for(int i =0;i<id;i++)
		{
			if(cc[i]==0)
			{
				if(sum>maxx)
				{
					maxx = sum;
				}
				sum = 0;
			}
			else
				sum+=cc[i];
		}
		if(sum>maxx)
		{
			maxx = sum;
		}
		return maxx;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.longestValidParentheses("())");
}

