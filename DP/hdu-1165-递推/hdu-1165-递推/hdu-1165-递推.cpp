// hdu-1165-递推.cpp : 定义控制台应用程序的入口点。
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
int dp[4][1000005]={0}; 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,m,i,j;
	for(i = 0;i<1000001;i++)
		dp[0][i]=i+1;
	for(i = 0;i<1000001;i++)
		dp[1][i]=i+2;
	for(i = 0;i<1000001;i++)
		dp[2][i]=i+i+3;
	dp[3][0]=5;
	for(i = 1;i<25;i++)
	{
		dp[3][i]=2*dp[3][i-1]+3;
	}
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d\n",dp[m][n]);
	}
}

