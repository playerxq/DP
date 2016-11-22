// hdu-1337-DP.cpp : 定义控制台应用程序的入口点。
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
int a[101];
int n;
void init()
{
	for(int i = 1;i<=100;i++)
		a[i]=1;
	for(int i = 2;i<=100;i++)
	{
		for(int j = i;j<=100;j+=i)
		{
			a[j]++;//j含有约数i 故约数个数加1
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	init();
	while(T--)
	{
		scanf("%d",&n);
		int cnt = 0;
		for(int i = 1;i<=n;i++)
		{
			if(a[i]%2)
				cnt++;
		}
		printf("%d\n",cnt);
	}
}

