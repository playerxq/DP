// hdu-1024-分组最大和.cpp : 定义控制台应用程序的入口点。
//dp[i][j]为1:j组成i组的最大和
//dp[i][j]=Max(dp[i-1][j-1]+Num[i]，Max(dp[0][j-1]~dp[i-1][j-1])+Num[i])//即num[i]单独一组或者和前面某些数合并 若合并则改变组数为0:i-1的已有情况
//Max(dp[0][j-1]~dp[i-1][j-1])用mmax[j-1]记录
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
int a[1000000+1];
int m,n;
int _max;
int dp[1000000+1];//
int mmax[1000000+1];
void init()
{
	memset(mmax,0,sizeof(mmax));
	memset(dp,0,sizeof(dp));
}
void solve()
{
	for(int i = 1;i<=m;i++)
	{
		_max = -1*INF;
		for(int j = i;j<=n;j++)
		{
			dp[j]=max(dp[j-1]+a[j],mmax[j-1]+a[j]);
			mmax[j-1] = _max;
			_max = max(_max,dp[j]);
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		init();
		solve();
		printf("%d\n",_max);
	}
}
