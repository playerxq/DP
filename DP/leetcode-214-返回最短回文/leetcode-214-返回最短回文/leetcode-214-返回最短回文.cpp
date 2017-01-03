// leetcode-214-返回最短回文.cpp : 定义控制台应用程序的入口点。
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
	int* P;
	int get_P(string s)
	{
		int j = -1;
		int i = 1;
		for(;i<s.length();i++)
		{
			while(j>=0&&s[i]!=s[j+1])
				j = P[j];
			if(s[i]==s[j+1])
			{
				j++;
				P[i] = j;
			}
		}
		return 0;
	}
    string shortestPalindrome(string s) {
        string res = "";
		if(s.length()-1==0)
			return s;
		P = new int[2*s.length()+1];
		for(int k = 0;k<2*s.length()+1;k++)
			P[k] = -1;
		get_P(s);
		int i = 0;
		int j = s.length()-1;
		int st = 0;
		while(i<j)
		{
			if(s[i]==s[j])
			{
				res+=(s[i]);
				i++;
				j--;
			}
			else
			{
				res+=(s[j]);
				int k = -1;
				for(int t = 0;t<res.length();t++)
				{
					while(k>=0&&res[t]!=s[k+1])
						k = P[k];
					if(res[t]==s[k+1])
					{
						k++;
					}
				}
				i = k+1;
				j--;
			}
		}
		if(i==j)
		{
			string ss = res;
			std::reverse(ss.begin(),ss.end());
			res+=s[i];
			res.append(ss);
		}
		else
		{
			string ss = res;
			std::reverse(ss.begin(),ss.end());
			res.append(ss);
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.shortestPalindrome("babbbabbaba");
}

