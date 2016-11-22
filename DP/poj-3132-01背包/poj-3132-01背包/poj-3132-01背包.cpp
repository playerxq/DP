// poj-3132-01背包.cpp : 定义控制台应用程序的入口点。
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
int prime[1200];
int is_prime[1200],idx;
int n,k;
int dp[1200][15];
void init()
{
	memset(is_prime,0,sizeof(is_prime));
	is_prime[1]=1;
	is_prime[2]=0;
	for(int i = 2;i<=1120;i++)
	{
		if(is_prime[i]==0)
		{
			for(int j = i*i;j<=1120;j+=i)
			{
				is_prime[j]=1;
			}
		}
	}
	idx = 0;
	for(int i = 2;i<=1120;i++)
	{
		if(!is_prime[i])
			prime[idx++]=i;
	}
	//对第一个素数
	dp[0][0]=1;
	dp[prime[0]][1]=1;
	for(int i = 1;i<idx;i++)//考察第i个素数
	{
		for(int j = 1120;j>=prime[i];j--)
		{
			for(int m = 1;m<=14;m++)
			{
				dp[j][m]+=dp[j-prime[i]][m-1];
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==0&&k==0)
			break;
		printf("%d\n",dp[n][k]);
	}
}

