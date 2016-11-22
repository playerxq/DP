// uva-10304-optimal binary tree.cpp : 定义控制台应用程序的入口点。
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
int a[255];
int d[255][255];
int w[255];
int dp()
{
	for(int r = 1;r<n;r++)
	{
		for(int i = 1;i<=n-r;i++)
		{
			int j = i+r;
			d[i][j] = d[i+1][j]+w[j]-w[i];
			for(int k = i+1;k<j;k++)
			{
				d[i][j] = min(d[i][j],d[i][k-1]+d[k+1][j]+w[j]-w[i-1]-a[k]);
			}
			d[i][j] = min(d[i][j],d[i][j-1]+w[j-1]-w[i-1]);
		}
	}
	return d[1][n];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(w,0,sizeof(w));
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		w[1] = a[1];
		for(int i = 2;i<=n;i++)
		{
			w[i] = a[i];
			w[i]+=w[i-1];
		}
		int ans = dp();
		printf("%d\n",ans);
	}
	return 0;
}

