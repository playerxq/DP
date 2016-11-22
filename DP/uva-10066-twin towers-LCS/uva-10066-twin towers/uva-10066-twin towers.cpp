// uva-10066-twin towers.cpp : 定义控制台应用程序的入口点。
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
int N1,N2;
int a[101];
int b[101];
int d[101][101];
int lcs()
{
	for(int i = 0;i<=N1;i++)
		d[i][0] = 0;
	for(int i = 0;i<=N2;i++)
		d[0][i] = 0;
	for(int i = 1;i<=N1;i++)
	{
		for(int j = 1;j<=N2;j++)
		{
			if(a[i-1]==b[j-1])
			{
				d[i][j] = d[i-1][j-1]+1;
			}
			else
				d[i][j] = d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];
		}
	}
	return d[N1][N2];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&N1,&N2))
	{
		if(N1==0&&N2==0)
			break;
		for(int i = 0;i<N1;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i<N2;i++)
			scanf("%d",&b[i]);
		//sort(a,a+N1);
		//sort(b,b+N2);
		int ans = lcs();
		printf("Twin Towers #%d\n",ncase++);
		printf("Number of Tiles : %d\n",ans);
		printf("\n");
	}
	return 0;
}

