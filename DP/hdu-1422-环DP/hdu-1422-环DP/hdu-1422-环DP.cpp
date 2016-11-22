// hdu-1422-��DP.cpp : �������̨Ӧ�ó������ڵ㡣
//��0��j-1����ǡ������ ��j������ʱ  ���k 0<k<j-1��j-1�����г���0:j-1�������������

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
int dp[100001];
int p[100001];
int w[100001];
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		int maxn = 0;
		for(int i = 0;i<n;i++)
		{
			memset(dp,0,sizeof(dp));
			int cnt = 0;
			if(p[i]>=w[i])
			{
				dp[i]=p[i]-w[i];
				cnt = 1;
				maxn = max(1,maxn);
			}
			else
			{
				continue;
			}
			int pre = i;
			int j = (i+1>=n)?0:(i+1);
			for(;j!=i;)
			{
				if(dp[pre]>=0&&dp[pre]+p[j]-w[j]>=0)
				{
					dp[j]=dp[pre]+p[j]-w[j];
					cnt++;
					pre= j;
					j = (j+1>=n)?0:(j+1);
				}
				else
					break;
			}
			if(j==i)
			{
				maxn = n;
				break;
			}
			else
			{
				if(cnt>maxn)
					maxn = cnt;
				if(j<=i)
					break;
				i = j;
			}
		}
		printf("%d\n",maxn);
	}
}

