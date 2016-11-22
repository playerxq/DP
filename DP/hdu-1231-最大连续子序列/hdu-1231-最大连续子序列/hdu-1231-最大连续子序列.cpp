// hdu-1231-最大连续子序列.cpp : 定义控制台应用程序的入口点。
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
int n;
int a[10001];
int dp[10001];
int st[10001];
int ed[10001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(st,0,sizeof(st));
		memset(ed,0,sizeof(ed));
		int k = 0;
		for(;k<n;k++)
		{
			if(a[k]>=0)
				break;
		}
		if(k==n)
		{
			printf("0 %d %d\n",a[0],a[n-1]);
			continue;
		}
		dp[0]=a[0];
		st[0]=ed[0]=0;
		for(int i = 1;i<n;i++)
		{
			if(a[i]>0)
			{
				if(dp[i-1]<0)
				{
					st[i]=i;
					ed[i]=i;
					dp[i]=a[i];
				}
				else
				{
					st[i]=st[i-1];
					ed[i]=i;
					dp[i]=dp[i-1]+a[i];
				}
			}
			else
			{
				if(dp[i-1]+a[i]>=a[i])
				{
					st[i]=st[i-1];
					ed[i]=i;
					dp[i]=dp[i-1]+a[i];
				}
				else
				{
					st[i]=i;
					ed[i]=i;
					dp[i]=a[i];
				}
			}
		}
		int maxx = -1;
		int ind = -1;
		for(int i = 0;i<n;i++)
		{
			if(dp[i]>maxx)
			{
				ind = i;
				maxx = dp[i];
			}
		}
		printf("%d %d %d\n",dp[ind],a[st[ind]],a[ed[ind]]);
	}
}

