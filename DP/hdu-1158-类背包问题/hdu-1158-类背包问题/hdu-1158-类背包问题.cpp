// hdu-1158-类背包问题.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 100000+10;
const int inf = 222222222;
int val[13];
int cost_hire,cost_fire,salary;
int dp[13][maxn];
int n;
int max_val;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		max_val = 0;
		scanf("%d%d%d",&cost_hire,&salary,&cost_fire);
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&val[i]);
			if(max_val<val[i])
				max_val=val[i];
		}
		int mm = max_val*(cost_hire)+salary*max_val*n;
		for(int i = 0;i<=n;i++)
			for(int j = 0;j<=max_val;j++)
			{
				if(i==0) dp[0][j]=0;
				else dp[i][j]=inf;
			}
		for(int i = val[1];i<=max_val;i++)
			dp[1][i]=i*(cost_hire+salary);
		for(int i = 2;i<=n;i++)
		{
			for(int j = val[i];j<=max_val;j++)
			{
				for(int k = val[i-1];k<=max_val;k++)
				{
					//if(dp[i-1][k]!=-1)
					{
						if(k<j)
						{
							//if(dp[i][j]==-1)
								//dp[i][j]=dp[i-1][k]+(j-k)*cost_hire+j*salary;
							//else
								dp[i][j]=min(dp[i][j],dp[i-1][k]+(j-k)*cost_hire+j*salary);
						}
						else if(k>j)
						{
							//if(dp[i][j]==-1)
								//dp[i][j]=dp[i-1][k]+(k-j)*cost_fire+j*salary;
							//else
								dp[i][j]=min(dp[i][j],dp[i-1][k]+(k-j)*cost_fire+j*salary);
						}
						else
						{
							//if(dp[i][j]==-1)
								//dp[i][j]=dp[i-1][k]+j*salary;
							//else
								dp[i][j]=min(dp[i][j],dp[i-1][k]+j*salary);
						}
					}
				}
			}
		}
		int inx;
		int minx = inf;
		for(int i = val[n];i<=max_val;i++)
		{
			if(dp[n][i]<minx)
				minx=dp[n][i];
		}
		printf("%d\n",minx);
	}
}

