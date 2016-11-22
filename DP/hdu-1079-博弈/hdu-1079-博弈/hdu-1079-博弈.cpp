// hdu-1079-博弈.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int dp[500][20][40];  
int day[400];
int mm[15]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
int dfs(int y, int m, int d)
{
	if(dp[y][m][d]!=-1)
		return dp[y][m][d];
	if(y>101)
		return dp[y][m][d]=0;
	int a,b;
	if((m==2&&d== day[y])||(m<12&&mm[m]==d&&mm[m+1]>=d))
	{
		a = dfs(y,m+1,d);
		b = dfs(y,m+1,1);
		if(a==0||b==0)
			return dp[y][m][d]=1;
		if(a&&b)
			return dp[y][m][d]=0;
	}
	else if((m==2&&d<day[y])||(mm[m]>d))
	{
		a = dfs(y,m,d+1);
		if(m<12)
			b = dfs(y,m+1,d);
		else
			b = dfs(y+1,1,d);
		if(a==0||b==0)
			return dp[y][m][d]=1;
		if(a&&b)
			return dp[y][m][d]=0;
	}
	else if(m==12&&d==mm[12])
	{
		a = dfs(y+1,1,1);
		b = dfs(y+1,1,d);
		if(a==0||b==0)
			return dp[y][m][d]=1;
		if(a&&b)
			return dp[y][m][d]=0;
	}
	else if(m<12 && mm[m]==d && mm[m+1]<d)
	{
		a = dfs(y,m+1,1);
		if(a==0)
			return dp[y][m][d]=1;
		if(a)
			return dp[y][m][d]=0;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int y,m,d;  
   int t;  
   memset(dp,-1,sizeof(dp));  
   for(int i=1900;i<=2001;i++)
   {
	if(i%4==0&&i%100!=0 || i%400==0) day[i-1900+1]=29;   
	else day[i-1900+1]=28;   
   }
   dp[101][11][4]=0;  
   for(int i=5;i<=mm[11];i++) dp[101][11][i]=1;  
   for(int i=1;i<=mm[12];i++) dp[101][12][i]=1;  
   scanf("%d",&t);  
   while(t--)  
   {  
       scanf("%d%d%d",&y,&m,&d);  
       y-=1900;   
       dfs(y,m,d);// cout<<"**= "<<sg[101][11][4]<<"   "<<sg[101][11][3]<<endl;  
       if(dp[y][m][d]==1) printf("YES\n");  
       else printf("NO\n");  
   }  
   return 0;
}

