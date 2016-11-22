// uva-10271-chopsticks.cpp : �������̨Ӧ�ó������ڵ㡣
//Ҫ��ѡ��k=k+8����Ԫ�飨��n�����У���Ҫ����������x<=y<=z,���д���Ϊ(x-y)^2������С�Ĵ����Ƕ��١�

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
int k,n;
int a[5001];
int d[1001][5001];//d[i][j]Ϊj:n����ѡi��
int dp()
{
	for(int i = 0;i<=n;i++)
		d[0][i] = 0;
	for(int i = 1;i<=k;i++)//j:n��n-j+1����ѡi�Լ�3*i����  ��j<=n+1-3*i  ʣ��j-1������Ӧk-i������ǰ2���� 2*(k-i)
	{
		for(int j = n+1-3*i;j>=1+2*(k-i);j--)
		{
			d[i][j] = d[i][j+1];
			d[i][j] = min(d[i][j],d[i-1][j+2]+(a[j]-a[j+1])*(a[j]-a[j+1]));//ѡ��j j+1
		}
	}
	return d[k][1];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&n);
		memset(a,0,sizeof(a));
		memset(d,0x7f,sizeof(d));
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		k+=8;
		int ans = dp();
		printf("%d\n",ans);
	}
	return 0;
}

