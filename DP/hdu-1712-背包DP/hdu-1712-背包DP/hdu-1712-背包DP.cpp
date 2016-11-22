// hdu-1712-背包DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[150],a[150][150];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)>0&&(n+m))
    {
        for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)//容量j天
            {
                for(int k=1;k<=j;k++)//用某一天来做第i个事情 则前i-1个事情在j-k天做
					if(dp[j]<dp[j-k]+a[i][k])
						dp[j]=dp[j-k]+a[i][k];
            }
        }
        printf("%d\n",dp[m]);
    }   
    return 0;
}

