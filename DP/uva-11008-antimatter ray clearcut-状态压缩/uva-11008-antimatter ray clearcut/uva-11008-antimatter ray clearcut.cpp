// uva-11008-antimatter ray clearcut.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define INF 0x3f3f3f3f
#define N (1<<16)+100
typedef struct PPP
{
	int x;
	int y;
} pp;
pp a[20];
int d[N];
int n,m;
bool ok(int i,int j,int k)
{
    int ax=a[i].x-a[j].x,bx=a[i].y-a[j].y;
    int cx=a[j].x-a[k].x,dx=a[j].y-a[k].y;
    return ax*dx==bx*cx;
}
int dp(int count,int st)
{
	if(d[st]!=INF)
		return d[st];
	if(count<=0)
		return 0;
	if(count==1)//ֻ���ٿ�һ����
		return d[st] = 1;
	for(int i = 0;i<n;i++)//�Ե�ǰ����״̬st������������γɵ�ֱ���и���ʣ��״̬
	{
		if((1<<i)&st)
		{
			for(int j = i+1;j<n;j++)
			{
				if((1<<j)&st)
				{
					int t = st;
					int cnt = 0;
					for(int k = i;k<n;k++)//����ͬһֱ���ϵ�
					{
						if(((1<<k)&st)&&(ok(i,j,k)))
						{
							cnt++;
							t-=(1<<k);
						}
					}
					d[st] = min(d[st],dp(count-cnt,t)+1);
				}
			}
		}
	}
	return d[st];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 1;

	while(T--)
	{
		if(ncase>1)
			printf("\n");
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for(int i = 0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		printf("Case #%d:\n",ncase++);
		int ans = 0;
		memset(d,INF,sizeof(d));
		printf("%d\n",dp(m,(1<<n)-1));
	}
	return 0;
}

