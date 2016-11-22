// uva-10534-wavio sequence.cpp : 定义控制台应用程序的入口点。
//前后求单调序列

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
#define min(a, b) ((a) < (b) ? (a) : (b))
int N;
int a[10001];
int f_in[10001];
int f_de[10001];
int B[10001];
int binary_search(int be, int end,int x)
{
	while(be<end)
	{
		int mid = be+(end-be)/2;
		if(B[mid]<x)
			be = mid+1;
		else if(B[mid]>x)
			end = mid;
		else
			return mid;
	}
	return be;
}
int last;
int get_longest_increase()
{
	B[0] = (-1);
	B[1] = a[0];
	last = 2;
	f_in[0] = 1;
	for(int i = 1;i<N;i++)
	{
		int be = 1;
		int end = last;
		if(a[i]>B[last-1])
		{
			f_in[i] = last;
			B[last++] = a[i];
		}
		else
		{
			int index = binary_search(be,end,a[i]);//返回第一个大于a[i]的值
			B[index] = a[i];
			f_in[i] = index;
		}
	}
	B[0] = (-1);
	B[1] = a[N-1];
	last = 2;
	f_de[0] = 1;
	for(int i = N-1;i>=1;i--)
	{
		int be = 1;
		int end = last;
		if(a[i]>B[last-1])
		{
			f_de[i] = last;
			B[last++] = a[i];
		}
		else
		{
			int index = binary_search(be,end,a[i]);
			B[index] = a[i];
			f_de[i] = index;
		}
	}
	int ans = 0;  
    for (int i = 0; i < N; i++) {  
         if (ans < min(f_in[i], f_de[i]))  
                ans = min(f_in[i], f_de[i]);  
    }  
	return 2*ans-1;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&N)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i = 0;i<N;i++)
			scanf("%d",&a[i]);
		memset(B,0,sizeof(B));
		memset(f_in,0,sizeof(f_in));
		memset(f_de,0,sizeof(f_de));
		int ans = get_longest_increase();
		printf("%d\n",ans);
	}
	return 0;
}

