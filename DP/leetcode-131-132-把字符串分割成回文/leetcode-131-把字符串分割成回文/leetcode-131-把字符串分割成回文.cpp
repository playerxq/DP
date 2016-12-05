// leetcode-131-把字符串分割成回文.cpp : 定义控制台应用程序的入口点。
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
//返回划分方式
class Solution1 {
public:
	void dfs(string s, vector<vector<string>>& res,vector<string>& v)
	{
		if(s.length()==0)
		{
			res.push_back(v);
			return;
		}
		for(int i = 0;i<s.length();i++)
		{
			if(s[0]==s[i])
			{
				int x,y;
				x = 1;
				y = i-1;
				int flag = 0;
				while(x<=y)
				{
					if(s[x]!=s[y])
					{
						flag = 1;
						break;
					}
					else
					{
						x++;
						y--;
					}
				}
				if(!flag)
				{
					v.push_back(s.substr(0,i+1));
					dfs(s.substr(i+1),res,v);
					v.pop_back();
				}
				else
					continue;
			}
			else
				continue;
		}
	}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
		if(s.length()==0)
			return res;
		vector<string> v;
		dfs(s,res,v);
		return res;
    }
};
//返回最小的切数
class Solution {
public:
	int minx;
    int minCut(string s) {
		if(s.length()==0)
			return 0;
		int** dp = new int* [s.length()+1];
		
		for(int i = 0;i<s.length();i++)
			dp[i] = new int[s.length()+1];
		for(int i = 0;i<s.length();i++)
			for(int j = 0;j<s.length();j++)
				dp[i][j] =  0;
		for(int i = 0;i<s.length();i++)
			dp[i][i] = 1;
		for(int i = 0;i<s.length();i++)
		{
			for(int j = 0;j<=i;j++)
			{
				if(s[i]==s[j]&&(i-j<2||dp[j+1][i-1]))
					dp[j][i] = 1;
			}
		}
		int* cp = new int[s.length()+1];
		for(int i = 0;i<s.length();i++)
			cp[i] = i;
		for(int i = 0;i<s.length();i++)
		{
			for(int j = i;j>=0;j--)
			{
				if(dp[j][i])
					cp[i] = min(cp[i],(j==0?0:cp[j-1]+1));
			}
		}
		int ans = cp[s.length()-1];
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

