// poj-1745-数字表达式DP.cpp : 定义控制台应用程序的入口点。
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
int N,K;
int dp[10010][100];
int getMod(int a)
{
	return (a%K+K)%K;
}
int num[10010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i = 1;i<=N;i++)
		scanf("%d",&num[i]);
	memset(dp, 0, sizeof(dp));
	dp[1][getMod(num[1])]=1;
	for(int i = 2;i<=N;i++)
	{
		for(int j = 0;j<K;j++)
		{
			if(dp[i-1][j])
			{
				dp[i][getMod(j-num[i])]=dp[i][getMod(j+num[i])]=1;
			}
		}
	}
	if(dp[N][0])
		printf("Divisible\n");
	else
		printf("Not divisible\n");
}

