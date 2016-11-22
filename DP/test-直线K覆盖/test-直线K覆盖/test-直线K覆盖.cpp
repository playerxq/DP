// test-直线K覆盖.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
int w[100];
int wt[100];
int x[100];
int c[100];
int n,k,r;
int opt[50][100];//1：m开了i个店
int popt[50][100];//1:m开了i个  且m处开了
int cov(int j)//j处设立后能控制的最小的点
{
	int i;
	for(i = j;i>=1;i--)
	{
		if(x[j]-x[i]>r)
			break;
	}
	return i+1;
}
int unc(int j)//j处设立后不能被控制的最大的点
{
	int i;
	for(i = 1;i<=j;i++)
	{
		if(x[j]-x[i]<=r)
			break;
	}
	return i-1;
}
int dp()
{
	for(int i = 1;i<=n;i++)
	{
		popt[1][i] = c[i]+opt[0][unc(i)];
	}
	for(int i = 1;i<=n;i++)
	{
		if(i>1)
			opt[1][i] = opt[1][i-1]+w[i];
		else
			opt[1][i] = INT_MAX;
		int h = cov(i);
		int temp = INT_MAX;
		for(int k = h;k<=i;k++)
		{
			if(temp > popt[1][k])
				temp = popt[1][k];
		}
		opt[1][i] = min(opt[1][i],temp);
	}
	for(int i = 2;i<=k;i++)
	{
		//popt[i][j]
		for(int j = i;j<=n;j++)
		{
			popt[i][j] = INT_MAX;
			int h = unc(j);
			h = max(i-1,h);
			for(int k = h;k<=j;k++)
				popt[i][j] = min(popt[i][j],opt[i-1][k]);
			popt[i][j] += c[j];
		}
		//opt[i][j]
		for(int j = i;j<=n;j++)
		{
			if(j>i)
				opt[i][j] = w[j]+opt[i][j-1];
			else
				opt[i][j] = INT_MAX;
			int h = cov(j);
			h = max(h,i);
			for(int k = h;k<=j;k++)
			{
				opt[i][j] = min(opt[i][j],popt[i][k]);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&k,&r);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&w[i],&c[i]);
		if(i==1)
			wt[1] = w[1];
		else
		{
			wt[i] = w[i]+wt[i-1];
		}
	}
	opt[0][0] = 0;
	for(int i = 1;i<=n;i++)
		opt[0][i] = wt[i];
	dp();
	int minn = INT_MAX;
	for(int i = 1;i<=k;i++)
		if(opt[i][n]<minn)
			minn = opt[i][n];
	printf("%d",minn);
	return 0;
}

