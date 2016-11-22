// uva-437-tower of babylon.cpp : 定义控制台应用程序的入口点。
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
typedef struct SSS
{
	int x,y,z;
	void f(int a,int b,int c){x = a;y=b;z=c;}
} s;
s a[300];
int d[300];//d[i]为使用到i个方块时达到的最大高度
int cnt;
int _max(int a, int b)
{
	return a>b?a:b;
}
int get_ans()
{
	int maxn = -1;
	for(int i = 0;i<cnt;i++)//最大上升严格子序列
	{
		d[i] = a[i].z;
		for(int j = 0;j<i;j++)//第i个是否可以放到某个j下面
		{
			if(a[i].x>a[j].x&&a[i].y>a[j].y)
			{
				d[i] = _max(d[i],d[j]+a[i].z);
			}
		}
		if(d[i]>maxn)
			maxn = d[i];
	}
	return maxn;
}
int cmp(const void* _a, const void* _b)
{
	s* a = (s*)_a;
	s* b = (s*)_b;
	return a->x*a->y-b->x*b->y;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int ncase = 1;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		int x,y,z;
		cnt = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[cnt++].f(x,y,z);
			a[cnt++].f(x,z,y);
			a[cnt++].f(y,x,z);
			a[cnt++].f(y,z,x);
			a[cnt++].f(z,y,x);
			a[cnt++].f(z,x,y);
		}
		//qsort(a,cnt,sizeof(a[0]),cmp);
		memset(d,0,sizeof(0));
		int ans = get_ans();
		printf("Case %d: maximum height = %d\n",ncase++,ans);
	}
	return 0;
}

