// uva-10626-buy coke.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n,n1,n5,n10;
int d[100][220][720];
int vis[100][220][720];
int dp(int c, int n10, int n5, int n1)
{
	if(vis[n10][n5][n1])
		return d[n10][n5][n1];
	else if(c==0)
	{
		vis[n10][n5][n1] = 1;
		d[n10][n5][n1] = 0;
		return 0;
	}
	else  
    {  
        int res=1<<30;  
        if(n1>=8) res=min(res,dp(c-1,n10,n5,n1-8)+8);  //1��Ǯ����8�� ��8��1��ɼ۸�
        if(n1>=3&&n5>=1) res=min(res,dp(c-1,n10,n5-1,n1-3)+4);  //��3��1 1��5���
        if(n1>=3&&n10>=1) res=min(res,dp(c-1,n10-1,n5+1,n1-3)+4);  //��1��10 3��1 �һ�1��5
        if(n5>=2) res=min(res,dp(c-1,n10,n5-2,n1+2)+2);  //2��5  �һ�2��1
        if(n10>=1) res=min(res,dp(c-1,n10-1,n5,n1+2)+1);  //1��10  �һ�2��1
		vis[n10][n5][n1] = 1;
		d[n10][n5][n1] = res;
        return res;  
    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&n1,&n5,&n10);
		memset(d,0,sizeof(d));  
        memset(vis,0,sizeof(vis)); 
		printf("%d\n",dp(n,n10,n5,n1));
	}
	return 0;
}

