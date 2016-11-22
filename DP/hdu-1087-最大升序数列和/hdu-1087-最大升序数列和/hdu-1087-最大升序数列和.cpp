// hdu-1087-最大升序数列和.cpp : 定义控制台应用程序的入口点。
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
const int INF = 99999999;
int a[1000+10];
int sumx[1000+10];
int n;
int solve()
{
	memset(sumx,0,sizeof(sumx));
	sumx[0]=a[0];
	for(int i = 1;i<n;i++)
	{
		sumx[i]=a[i];
		for(int j = 0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				sumx[i]=max(sumx[i],sumx[j]+a[i]);
			}
		}
	}
	int tempx = sumx[0];
	for(int i = 1;i<n;i++)
	{
		if(tempx<sumx[i])
			tempx = sumx[i];
	}
	return tempx;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
}

