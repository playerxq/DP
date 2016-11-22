// uva-10271-chopsticks.cpp : 定义控制台应用程序的入口点。
//要你选出k=k+8对三元组（从n个数中）。要求这三个数x<=y<=z,其中代价为(x-y)^2。问最小的代价是多少。

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
int k,n;
int a[5001];
int d[1001][5001];//d[i][j]为j:n个数选i对
int dp()
{
	for(int i = 0;i<=n;i++)
		d[0][i] = 0;
	for(int i = 1;i<=k;i++)//j:n共n-j+1个数选i对即3*i个数  故j<=n+1-3*i  剩余j-1个数对应k-i对数的前2个数 2*(k-i)
	{
		for(int j = n+1-3*i;j>=1+2*(k-i);j--)
		{
			d[i][j] = d[i][j+1];
			d[i][j] = min(d[i][j],d[i-1][j+2]+(a[j]-a[j+1])*(a[j]-a[j+1]));//选定j j+1
		}
	}
	return d[k][1];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&n);
		memset(a,0,sizeof(a));
		memset(d,0x7f,sizeof(d));
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		k+=8;
		int ans = dp();
		printf("%d\n",ans);
	}
	return 0;
}

