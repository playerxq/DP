// hdu-1712-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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
            for(int j=m;j>=1;j--)//����j��
            {
                for(int k=1;k<=j;k++)//��ĳһ��������i������ ��ǰi-1��������j-k����
					if(dp[j]<dp[j-k]+a[i][k])
						dp[j]=dp[j-k]+a[i][k];
            }
        }
        printf("%d\n",dp[m]);
    }   
    return 0;
}

