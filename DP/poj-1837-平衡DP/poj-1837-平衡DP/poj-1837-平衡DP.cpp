// poj-1837-ƽ��DP.cpp : �������̨Ӧ�ó������ڵ㡣
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
int dp[25][15001];//ǰi��������ϲ�������Ϊj�ķ�����
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
		dp[1][pos[i]*val[1]+7500]=1;//��һ������ҵ�λ��
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

