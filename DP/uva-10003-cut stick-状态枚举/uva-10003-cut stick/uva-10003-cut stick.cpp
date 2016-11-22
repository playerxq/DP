// uva-10003-cut stick.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<cstdio>
#include <cmath>
#include<string.h>
using namespace std;

int d[51][51];//�ӵ�i���жϵ���j���жϵõ������Ž�
int an[52];
int l,n;

int dp( int i, int j)//��i����j��   
{
	if( j== i+1)
		return d[i][j]=0;
	if( d[i][j]!=-1)
		return d[i][j];
	d[i][j] =1000000000;
	int k;
	for( k=i+1; k<j; k++)
		d[i][j] = min( d[i][j], dp(i,k)+dp(k,j)+an[j]-an[i]);
	return d[i][j];
}

int main()
{
		freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while( scanf("%d",&l) &&l)
	{
		scanf("%d",&n);
		int i;
		memset(d, -1, sizeof( d));
		for( i=1; i<=n; i++)
			scanf("%d",&an[i]);
		an[0] =0; an[n+1] =l;   //���ͷβ�������
		printf("The minimum cutting is %d.\n", dp(0,n+1));//��0����n+1���ж�
	}
	return 0;
}

