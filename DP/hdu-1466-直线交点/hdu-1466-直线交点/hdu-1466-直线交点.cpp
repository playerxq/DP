// hdu-1466-直线交点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int res[25][200];
int len[25];
int n;
void init()
{
	res[0][len[0]++]=0;
	res[1][len[1]++]=0;
	res[2][len[2]++]=0;
	res[2][len[2]++]=1;
	for(int i = 3;i<21;i++)
	{
		res[i][len[i]++]=0;//全平行情况
		//第i条线与前i-1条没有平行线 则新产生i-1个交点+(i-1)条线的所有交点情况
		//第i条线与前i-1条线有一个平行线 则新产生2*(i-2)个焦点+(i-2)条交点的所有情况
		//。。。
		//第i条线前i-1条线有i-2个平行线 新产生(i-1)*1个交点+1条直线所有情况
		//全部平行  不产生新的交点
		for(int j = i-1;j>=1;j--)
		{
			for(int t = 0;t<len[j];t++)
			{
				int k;
				for(k = 0;k<len[i];k++)
				{
					if(res[i][k]==res[j][t]+(i-j)*j)
						break;
				}
				if(k==len[i])
				{
					res[i][len[i]++]=res[j][t]+(i-j)*j;
				}
			}
		}
		sort(res[i],res[i]+len[i]);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<len[n];i++)
		{
			printf("%d",res[n][i]);
			if(i<len[n]-1)
				printf(" ");
		}
		printf("\n");
	}
}

