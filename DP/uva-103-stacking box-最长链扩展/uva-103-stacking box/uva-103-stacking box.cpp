// uva-103-stacking box.cpp : 定义控制台应用程序的入口点。
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
int k,n;
typedef struct Point
{
	int a[11];
	int id;
} po;
int g[31][31];
po parr[31];
int src[31];
int des[31];
int d[31];
int ok(int inside, int outside)
{
	for(int i = 0;i<n;i++)
	{
		if(parr[inside].a[i]>=parr[outside].a[i])
			return 0;
	}
	return 1;
}
void construct()
{
	for(int i = 0;i<k;i++)
	{
		for(int j = 0;j<k;j++)
		{
			if(ok(i,j))//i嵌套于j中
			{
				g[i][j] = 1;
			}
		}
	}
}
int dp(int i)
{
	int& ans = d[i];
	if(ans>0)
		return ans;
	ans = 1;
	for(int j = 0;j<k;j++)
	{
		if(g[i][j])//i嵌套于j中
			ans = ans>=(dp(j)+1)?ans:(dp(j)+1);
	}
	return ans;
}
void printf_ans(int i)
{
	printf("%d",i+1);
	for(int j = 0;j<k;j++)
	{
		if(g[i][j]&&d[i]==d[j]+1)
		{
			printf(" ");
			printf_ans(j);
			break;
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		memset(g,0,sizeof(g));
		for(int i = 0;i<k;i++)
		{
			for(int j = 0;j<n;j++)
				scanf("%d",&parr[i].a[j]);
			sort(parr[i].a,parr[i].a+n);
			parr[i].id = i;
		}
		construct();
		memset(d,0,sizeof(d));
		int maxn = -1;
		int max_i = -1;
		for(int i = 0;i<k;i++)
		{
			int ans = dp(i);
			if(ans>maxn)
			{
				maxn = ans;
				max_i = i;
			}
		}
		printf("%d\n",maxn);
		printf_ans(max_i);
		printf("\n");
	}
	return 0;
}
