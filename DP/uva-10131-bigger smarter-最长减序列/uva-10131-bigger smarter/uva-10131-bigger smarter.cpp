// uva-10131-bigger smarter.cpp : 定义控制台应用程序的入口点。
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
typedef struct elephant
{
	int w;
	int iq;
	int id;
} ele;
ele earr[1001];
int n;
int maxn;
int f[1001];
int pre[1001];
int cmp(const void* _a, const void* _b)
{
	ele* a = (ele*)_a;
	ele* b = (ele*)_b;
	return a->w-b->w;
}
void print_pre(int now)
{
	if(maxn--)
	{
		print_pre(pre[now]);
		printf("%d\n",earr[now].id);
	}
}
void dp()
{
	for(int i = 0;i<n;i++)
	{
		f[i] = 1;
		pre[i] = -1;
	}
	for(int i = 1;i<n;i++)//找到最长iq递减序列
	{
		for(int j = 0;j<i;j++)
		{
			if(earr[j].iq>earr[i].iq&&earr[j].w!=earr[i].w&&f[j]+1>f[i])
			{
				f[i] = f[j]+1;
				pre[i] = j;
			}
		}
	}
	maxn = -1;
	int index_i = -1;
	for(int i = 0;i<n;i++)
	{
		if(f[i]>maxn)
		{
			index_i = i;
			maxn = f[i];
		}
	}
	printf("%d\n",maxn);
	print_pre(index_i);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int we,iqa;
	while(scanf("%d%d",&we,&iqa)!=EOF)
	{
		earr[n].iq = iqa;
		earr[n].w = we;
		earr[n].id = n+1;
		n++;
	}
	qsort(earr,n,sizeof(ele),cmp);//按体重升序
	dp();
	return 0;
}

