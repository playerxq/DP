// hdu-1058-humble num-素因子.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3f3f3f3f;
int a[5843];
int n;
void init()
{
	memset(a,0,sizeof(a));
	a[1]=1;
	for(int i = 2;i<5843;i++)
	{
		int temp1,temp2,temp3,temp4;
		temp1=temp2=temp3=temp4=0;
		for(int j = 1;j<i;j++)
		{
			if(a[j]*2>a[i-1])
			{
				temp1 = a[j]*2;
				break;
			}
		}
		for(int j = 1;j<i;j++)
		{
			if(a[j]*3>a[i-1])
			{
				temp2 = a[j]*3;
				break;
			}
		}
		for(int j = 1;j<i;j++)
		{
			if(a[j]*5>a[i-1])
			{
				temp3 = a[j]*5;
				break;
			}
		}
		for(int j = 1;j<i;j++)
		{
			if(a[j]*7>a[i-1])
			{
				temp4 = a[j]*7;
				break;
			}
		}
		a[i]=min(temp1,min(temp2,min(temp3,temp4)));
	}
}
int get_suffix(int n)
{
	int h,l,cnt,nx;
	cnt = 0;
	l = n%10;
	nx=n%100/10;
	while(n)
	{
		cnt++;
		h = n%10;
		n = n/10;
	}
	if(h==1&&cnt==1)
	{
		if(l==1)
			return 1;//st
		else if(l==2)
			return 2;//nd
		else if(l==3)
			return 3;//rd
		else
			return 4;//th
	}
	else if(h==1&&cnt==2)
	{
		return 4;
	}
	else if(cnt>2&&nx==1)
		return 4;
	else
	{
		if(l==1)
			return 1;//st
		else if(l==2)
			return 2;//nd
		else if(l==3)
			return 3;//rd
		else
			return 4;//th
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)==1&&n)
	{
		int g = get_suffix(n);
		if(g==1)
			printf("The %dst humble number is %d.\n",n,a[n]);
		else if(g==2)
			printf("The %dnd humble number is %d.\n",n,a[n]);
		else if(g==3)
			printf("The %drd humble number is %d.\n",n,a[n]);
		else
			printf("The %dth humble number is %d.\n",n,a[n]);
	}
}

