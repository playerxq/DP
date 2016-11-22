// hdu-1723-链路递推.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int dp[31];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!n&&!m)
			break;
		memset(dp,0,sizeof(dp));
		dp[1]=1;
		for(int i = 2;i<=n;i++)
		{
			for(int k = 1;k<=m;k++)
			{
				if(i-k>=1&&dp[i-k]!=0)
				{
					dp[i]+=dp[i-k];
				}
			}
		}
		printf("%d\n",dp[n]);
	}
}

