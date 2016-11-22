// hdu-1506-最大全0矩阵.cpp : 定义控制台应用程序的入口点。
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
long long a[100001];
long long l[100001];
long long r[100001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i = 1;i<=n;i++)
			scanf("%lld",&a[i]);
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		a[0]=a[n+1]=-1;
		for(int i = 1;i<=n;i++)
			l[i]=r[i]=i;
		long long  maxx = -1;
		for(int i = 2;i<=n;i++)
		{
			while(a[l[i]-1]>=a[i])
				l[i]=l[l[i]-1];
		}
		for(int i = n-1;i>=1;i--)
		{
			while(a[r[i]+1]>=a[i])
				r[i]=r[r[i]+1];
		}
		for(int i = 1;i<=n;i++)
		{
			if(maxx<(r[i]-l[i]+1)*a[i])
				maxx = (r[i]-l[i]+1)*a[i];
		}
		printf("%lld\n",maxx);
	}
}

