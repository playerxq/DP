// hdu-1024-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[i][j]Ϊ1:j���i�������
//dp[i][j]=Max(dp[i-1][j-1]+Num[i]��Max(dp[0][j-1]~dp[i-1][j-1])+Num[i])//��num[i]����һ����ߺ�ǰ��ĳЩ���ϲ� ���ϲ���ı�����Ϊ0:i-1���������
//Max(dp[0][j-1]~dp[i-1][j-1])��mmax[j-1]��¼
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
