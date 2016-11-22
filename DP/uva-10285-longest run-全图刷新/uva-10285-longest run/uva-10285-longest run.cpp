// uva-10285-longest run.cpp : 定义控制台应用程序的入口点。
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
int a[101][101];
int d[101][101];
int r,c;
int flag;
int get_ans()
{
	while(flag)//有更新
	{
		flag = 0;
		for(int i = 0;i<r;i++)//每个点的四个方向
		{
			for(int j = 0;j<c;j++)
			{
				if(i>0&&d[i][j]<d[i-1][j]+1&&a[i][j]<a[i-1][j])
				{
					flag = 1;
					d[i][j] = d[i-1][j]+1;
				}
				if(j>0&&d[i][j]<d[i][j-1]+1&&a[i][j]<a[i][j-1])
				{
					flag = 1;
					d[i][j] = d[i][j-1]+1;
				}
				if(i<r-1&&d[i][j]<d[i+1][j]+1&&a[i][j]<a[i+1][j])
				{
					flag = 1;
					d[i][j] = d[i+1][j]+1;
				}
				if(j<c-1&&d[i][j]<d[i][j+1]+1&&a[i][j]<a[i][j+1])
				{
					flag = 1;
					d[i][j] = d[i][j+1]+1;
				}
			}
		}
	}
	int maxn = -1;
	for(int i = 0;i<r;i++)
		for(int j = 0;j<c;j++)
			if(d[i][j]>maxn)
				maxn = d[i][j];
	return maxn;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char name[101];
		scanf("%s%d%d",name,&r,&c);
		for(int i = 0;i<r;i++)
			for(int j = 0;j<c;j++)
				scanf("%d",&a[i][j]);
		flag = 1;
		for(int i = 0;i<r;i++)
			for(int j = 0;j<c;j++)
				d[i][j] = 1;
		int ans = get_ans();
		printf("%s: %d\n",name,ans);
	}
	return 0;
}

