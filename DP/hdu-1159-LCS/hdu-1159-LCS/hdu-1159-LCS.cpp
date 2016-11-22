// hdu-1159-LCS.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn =1000;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int len1,len2;
int LCS()
{
	for(int i = 1;i<=len1;i++)
	{
		for(int j = 1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
		}
	}
	return dp[len1][len2];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		memset(dp,0,sizeof(dp));
		printf("%d\n",LCS());
	}
}

