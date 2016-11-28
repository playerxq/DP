// leetcode-91-解码方式.cpp : 定义控制台应用程序的入口点。
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
    int numDecodings(string s) {
		int len = s.length();
		if(!len)
			return 0;
		int* dp = new int[len+1];
		for(int i = 0;i<len;i++)
			dp[i] = 0;
		if(s[0]-'0'>0)
			dp[0]=1;
		else
			dp[0] = 0;
		for(int i = 1;i<len;i++)
		{
			int t = (s[i-1]-'0')*10+s[i]-'0';
			if(s[i-1]-'0'>0&&t<=26&&t)
				dp[i] = (i>=2?dp[i-2]:1)+(s[i]-'0'>0?dp[i-1]:0);
			else
				dp[i] = (s[i]-'0'>0?dp[i-1]:0);
		}
		return dp[len-1];
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.numDecodings("12");
}

