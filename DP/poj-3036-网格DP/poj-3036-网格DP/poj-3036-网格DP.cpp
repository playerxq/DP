// poj-3036-网格DP.cpp : 定义控制台应用程序的入口点。
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
int n;
int dp[15][32][32];//原点是(15,15)
int dir[6][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,1},{1,-1}};
bool ok(int i, int j)
{
	return (i>=0&&i<=30&&j>=0&&j<=30);
}
void solve()
{
	memset(dp,0,sizeof(dp));
	dp[0][15][15]=1;
	for(int step=1;step<=n;step++)
	{
		for(int i = 0;i<=30;i++)
		{
			for(int j = 0;j<=30;j++)
			{
				for(int d = 0;d<6;d++)
				{
					int prex = i+dir[d][0];
					int prey = j+dir[d][1];
					if(ok(prex,prey))
					{
						if(dp[step-1][prex][prey])
							dp[step][i][j]+=dp[step-1][prex][prey];
					}
				}
			}
		}
	}
	printf("%d\n",dp[n][15][15]);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		solve();
	}
	return 0;
}

