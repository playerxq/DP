// hdu-1300-DP.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3f3f3f3f;
int n,a[101],p[101],sum[101];
int dp[101];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&p[i]);
			if(i==1)
				sum[1]=a[1];
			else
				sum[i]=sum[i-1]+a[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=n;i++)
		{
			dp[i]=INF;
			for(int j = 0;j<=i-1;j++)
			{
				dp[i]=min(dp[i],dp[j]+(10+sum[i]-sum[j])*p[i]);
			}
		}
		printf("%d\n",dp[n]);
	}
}

