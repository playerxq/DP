// poj-2392-多重背包.cpp : 定义控制台应用程序的入口点。
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
struct goods
{
	int h,hmax,n;
} good[500];
int cmp(struct goods& a, struct goods& b)
{
	return a.hmax<b.hmax;
}
int dp[400000],sum[400000];  
int k;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&k)!=EOF)
	{
		for(int i = 0;i<k;i++)
			scanf("%d%d%d",&good[i].h,&good[i].hmax,&good[i].n);
		sort(good,good+k,cmp);//按最大高度升序排序保证最低的石块优先考虑
		dp[0]=1;
		int ans = 0;
		for(int i = 0;i<k;i++)//依次考虑每个石块
		{
			memset(sum,0,sizeof(sum));  //sum[j]表示总高度j时i号石块用的个数
			for(int j = good[i].h;j<=good[i].hmax;j++)//加上若干i号石块的总高度
			{
				if(!dp[j]&&dp[j-good[i].h]&&sum[j-good[i].h]<good[i].n)
				{
					dp[j]=1;
					sum[j]=sum[j-good[i].h]+1;
					if(ans<j)
						ans = j;
				}
			}
		}
		printf("%d\n",ans);
	}
}

