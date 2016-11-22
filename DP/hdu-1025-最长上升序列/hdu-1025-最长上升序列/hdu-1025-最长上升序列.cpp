// hdu-1025-最长上升序列.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 500005;
int poor[maxn],res[maxn],len;
int binary_s(int be, int end, int x)
{
	while(be<=end)
	{
		int mid = (end+be)/2;
		if(res[mid]<x)
			be = mid+1;
		else
			end = mid-1;
	}
	return be;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,k,n,cas,_max,r,pos;
	cas = 1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(res,0,sizeof(res));
		len = 0;
		for(i = 1;i<=n;i++)
			res[i]=maxn;
		for(i = 1;i<=n;i++)
		{
			scanf("%d%d",&k,&r);
			poor[k]=r;
		}
		res[1]=poor[1];
		len = 1;
		for(int i = 2;i<=n;i++)
		{
			if(res[len]<poor[i])
				res[++len]=poor[i];
			else
			{
				pos = binary_s(1,len,poor[i]);
				res[pos]=poor[i];
			}
		}
		_max = len;
		if(_max==1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n",cas++,_max);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",cas++,_max);
	}
}

