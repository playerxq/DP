// poj-1157-简单DP.cpp : 定义控制台应用程序的入口点。
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
int val[101][101];
int dp[101][101];
int f,v;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&f,&v);
	for(int i = 1;i<=f;i++)
	{
		for(int j = 1;j<=v;j++)
		{
			scanf("%d",&val[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=v+1-f;i++)
	{
		dp[1][i]=val[1][i];
	}
	for(int i = 2;i<=f;i++)
	{
		for(int j = i;j<=v;j++)
		{
			dp[i][j]=val[i][j];
			int maxx = -10000;
			for(int k = i-1;k<=j-1;k++)
			{
				if(dp[i][j]+dp[i-1][k]>maxx)
					maxx = dp[i][j]+dp[i-1][k];
			}
			dp[i][j]=maxx;
		}
	}
	int ans = -10000;
	for(int i = 1;i<=v;i++)
	{
		if(dp[f][i]>ans)
			ans = dp[f][i];
	}
	printf("%d\n",ans);
}
