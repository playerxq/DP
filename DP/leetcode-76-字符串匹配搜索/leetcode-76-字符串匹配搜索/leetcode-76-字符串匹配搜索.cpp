// leetcode-76-字符串匹配搜索.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
		map<char, int> cur;
		for(int i = 0;i<t.size();i++)
			cur[t[i]]++;
		int cnt = 0;
		int min_len = INT32_MAX;
		int min_start = 0;
		int start = 0;
		for(int i = 0;i<s.size();i++)
		{
			if(cur[s[i]]-->0) cnt++;
			while(cnt==t.size())
			{
				if(i-start+1<min_len)
				{
					min_len = i-start+1;
					min_start = start;
				}
				if(cur[s[start++]]++==0) cnt--;
			}
		}
		if(min_len!=INT32_MAX)
			res = s.substr(min_start,min_len);
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

