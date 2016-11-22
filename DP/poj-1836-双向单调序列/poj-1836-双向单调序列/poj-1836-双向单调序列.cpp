// poj-1836-双向单调序列.cpp : 定义控制台应用程序的入口点。
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
#define min(a, b) ((a) < (b) ? (a) : (b))
const int MAXN = (1000 + 10);
int N;
double a[1001];
int f_in[1001];
int f_de[1001];
double B[1001];
int dp1[MAXN], dp2[MAXN];
bool mark1[MAXN], mark2[MAXN];
int binary_search(int be, int end,double x)
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
	B[1] = a[1];
	last = 2;
	f_in[1] = 1;
	for(int i = 2;i<N;i++)
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
	B[1] = a[N];
	last = 2;
	f_de[N] = 1;
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
	memset(mark1, false, sizeof(mark1));
	for (int i = 1; i <= N; i++) {
		int tmp = 0, index = 0;
		for (int j = 1; j <= i; j++) {
			if (f_in[j] > tmp) {
				tmp = f_in[j];
				index = j;
			}
		}
		dp1[i] = tmp;
		if (f_in[i] == tmp && index == i) mark1[i] = true;
	}
	memset(mark2, false, sizeof(mark2));
	for (int i = 1; i <= N; i++) {
		int tmp = 0, index = 0;
		for (int j = i; j <= N; j++) {
			if (f_de[j] >=  tmp) {
				tmp = f_de[j];
				index = j;
			} 
		}
		dp2[i] = tmp;
		if (f_de[i] == tmp && index == i) mark2[i] = true; 
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (mark1[i] && mark2[i]) ans = max(ans, dp1[i] + dp2[i] - 1);
		else ans = max(ans, dp1[i] + dp2[i]);
	}
	return N - ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&N)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i = 1;i<=N;i++)
			scanf("%lf",&a[i]);
		memset(B,0,sizeof(B));
		memset(f_in,0,sizeof(f_in));
		memset(f_de,0,sizeof(f_de));
		int ans = get_longest_increase();
		printf("%d\n",ans);
	}
	return 0;
}



