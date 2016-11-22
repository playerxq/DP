// hdu-1692-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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
int W[100001],L[100001],P[100001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T,t,n;
	scanf("%d",&T);
	t=0;
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
			scanf("%d%d%d",&W[i],&L[i],&P[i]);
		int minx = P[n-1];
		for(int i = 0;i<n;i++)//�ӵ�i����ʼ�ƻ�
		{
			int maxn;
			int sum;
			sum = maxn = 0;
			for(int j = i;j<n;j++)
			{
				maxn+=W[j];
				if(maxn<=L[j])
					sum+=P[j];
				if(sum>minx)
					break;
			}
			if(sum<minx)
				minx=sum;
		}
		printf("Case %d: Need to use %d mana points.\n",++t,minx);
	}
}

