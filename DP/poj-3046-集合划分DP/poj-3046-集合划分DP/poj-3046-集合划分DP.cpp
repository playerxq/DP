// poj-3046-集合划分DP.cpp : 定义控制台应用程序的入口点。
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
int T,A,S,B;
int val[100001];
int group[1001];
int dp[2][100001];//dp[j]表示前i个家族组成的集合大小为j的方法数  dp[j]+=dp[j-k] 0<=k<=group[i] j-k为i-1的状态 在相反维保存
int ans;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d%d%d",&T,&A,&S,&B);
	for(int i = 1;i<=A;i++)
	{
		scanf("%d",&val[i]);
	}
	sort(val,val+A);
	for(int i = 1;i<=A;i++)
	{
		group[val[i]]++;
	}
	for(int i = 0;i<=group[1];i++)
	{
		dp[1][i]=1;
	}
	for(int i = 2;i<=T;i++)
	{
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j = 0;j<=B;j++)
		{
			for(int k = 0;k<=group[i];k++)
			{
				if(j>=k&&dp[1-(i&1)][j-k]>0)
				{
					dp[i&1][j]+=dp[1-(i&1)][j-k];
					dp[i&1][j] = dp[i&1][j]%1000000;
				}
				else if(dp[1-(i&1)][j-k]==0)
				{
					continue;
				}
				else
					break;
			}
		}
	}
	ans = 0;
	for(int i = S;i<=B;i++)
	{
		ans+=dp[T&1][i];
		ans = ans%1000000;
	}
	printf("%d\n",ans);
}

