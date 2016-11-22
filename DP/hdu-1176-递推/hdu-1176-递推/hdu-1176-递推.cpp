// hdu-1176-递推.cpp : 定义控制台应用程序的入口点。
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
int n,max_T;
int val[100001][12];
int dp[100001][12];
int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=11;i++)
		dp[max_T][i]=val[max_T][i];
	for(int i = max_T-1;i>=0;i--)
	{
		for(int j = 1;j<=11;j++)
		{
			//if(dp[i-1][j]>=0)
			{
				dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+val[i][j];
			}
		}
	}
	return dp[0][6];
}
int main()
{
	
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(val,0,sizeof(val));
		max_T = 0;
		for(int i = 0;i<n;i++)
		{
			int x,T;
			scanf("%d%d",&x,&T);
			val[T][x+1]++;
			if(T>max_T)
				max_T = T;
		}
		printf("%d\n",solve());
	}
}
