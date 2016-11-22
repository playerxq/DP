// poj-2385-直接DP.cpp : 定义控制台应用程序的入口点。
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
int dp[1001][2][31];
int val[1001];
int t,w,ans;
void init()
{
	for(int i = 0;i<1001;i++)
		for(int j = 0;j<2;j++)
			for(int k = 0;k<31;k++)
				dp[i][j][k]=0;
	ans = -1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&t,&w);
	for(int i = 1;i<=t;i++)
		scanf("%d",&val[i]);
	init();
	for(int i = 1;i<=t;i++)
	{
		for(int j = 0;j<2;j++)
		{
			for(int k = 0;k<=w;k++)
			{
				if(val[i]==j+1)
				{
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+1);
					if(k)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][1-j][k-1]+1);
				}
				else
				{
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
					if(k)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][1-j][k-1]);
				}
			}
		}
	}
	for(int j = 0;j<=1;j++)
	{
		for(int k = 0;k<=w;k++)
			if(dp[t][j][k]>ans)
				ans = dp[t][j][k];
	}
	printf("%d\n",ans);
}

