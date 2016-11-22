// uva-562-divide coins.cpp : 定义控制台应用程序的入口点。
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
int m;
int c[105];
int d[105*500];//d[i]为当前的若干硬币能否组成总额为i的堆
int sum;
int minn;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		d[0] = 1;
		sum = 0;
		for(int i = 0;i<m;i++)
		{
			scanf("%d",&c[i]);
			sum+=c[i];
		}
		for(int i = 0;i<m;i++)//当前的i个硬币能否组成总额为j的堆
		{
			for(int j = sum;j>=c[i];j--)
			{
				if(d[j-c[i]])
					d[j] = 1;
			}
		}
		int i;
		for(i = sum/2;i>=0;i--)
			if(d[i])
				break;
		printf("%d\n",sum-2*i);//i:sum-i的差
	}
	return 0;
}

