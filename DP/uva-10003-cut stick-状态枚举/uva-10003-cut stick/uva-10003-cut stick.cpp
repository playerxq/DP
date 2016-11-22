// uva-10003-cut stick.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cstdio>
#include <cmath>
#include<string.h>
using namespace std;

int d[51][51];//从第i处切断到第j处切断得到的最优解
int an[52];
int l,n;

int dp( int i, int j)//第i处到j处   
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
		an[0] =0; an[n+1] =l;   //添加头尾两个结点
		printf("The minimum cutting is %d.\n", dp(0,n+1));//从0处与n+1处切断
	}
	return 0;
}

