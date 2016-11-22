// poj-2392-���ر���.cpp : �������̨Ӧ�ó������ڵ㡣
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
		sort(good,good+k,cmp);//�����߶���������֤��͵�ʯ�����ȿ���
		dp[0]=1;
		int ans = 0;
		for(int i = 0;i<k;i++)//���ο���ÿ��ʯ��
		{
			memset(sum,0,sizeof(sum));  //sum[j]��ʾ�ܸ߶�jʱi��ʯ���õĸ���
			for(int j = good[i].h;j<=good[i].hmax;j++)//��������i��ʯ����ܸ߶�
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

