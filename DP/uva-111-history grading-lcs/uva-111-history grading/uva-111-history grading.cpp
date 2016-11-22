// uva-111-history grading.cpp : 定义控制台应用程序的入口点。
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
int n;
int a[25];
int b[25];
int d[25][25];
int _max(int a, int b)
{
	return a>b?a:b;
}
int get_point()
{
	int res = 0;
	for(int i = 1;i<=n;i++)
	{
		if(a[i]==b[i])
			res++;
	}
	return res;
}
int get_lcs()
{
	for(int i = 1;i<=n;i++)
	{
		d[1][i] = 1;
		d[i][1] = 1;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(a[i]==b[j])
				d[i][j] = 1+d[i-1][j-1];
			else
			{
				d[i][j] = _max(d[i][j-1],d[i-1][j]);
			}
		}
	}
	return d[n][n];
}
int get_score()
{
	int res = 0;
	//res+=get_point();
	memset(d,0,sizeof(d));
	res+=get_lcs();
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	int c;
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&c);
		a[c] = i;
	}
	int k = 1;
	while(scanf("%d",&c)!=EOF)
	{
		b[c] = k++;
		if(k==n+1)
		{
			int score = get_score();
			printf("%d\n",score);
			memset(b,0,sizeof(b));
			k = 1;
		}
	}
	return 0;
}

