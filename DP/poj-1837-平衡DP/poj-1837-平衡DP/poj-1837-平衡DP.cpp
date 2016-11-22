// poj-1837-平衡DP.cpp : 定义控制台应用程序的入口点。
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
int G,C;
int pos[25];
int val[25];
int dp[25][15001];//前i个砝码挂上产生力矩为j的方案数
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&C,&G);
	for(int i = 1;i<=C;i++)
		scanf("%d",&pos[i]);
	for(int i = 1;i<=G;i++)
		scanf("%d",&val[i]);
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=C;i++)
	{
		dp[1][pos[i]*val[1]+7500]=1;//第一个砝码挂的位置
	}
	for(int i = 2;i<=G;i++)
	{
		for(int j = 0;j<15001;j++)
		{
			if(dp[i-1][j])
			{
				for(int k = 1;k<=C;k++)
				{
					dp[i][j+pos[k]*val[i]]+=dp[i-1][j];
				}
			}
		}
	}
	printf("%d\n",dp[G][7500]);
}

