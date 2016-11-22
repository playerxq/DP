// uva-10617-again palindrome.cpp : 定义控制台应用程序的入口点。
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
#define M 65  
int n;  
long long d[M][M] = {0};  
long long vis[M][M] = {0};  
char str[M];  
long long dp(int i, int j)
{
	if(vis[i][j])
		return d[i][j];
	if(i>j)
	{
		vis[i][j] = 1;
		d[i][j] = 0;
		return 0;
	}
	if(i==j)
	{
		vis[i][j] = 1;
		d[i][j] = 1;
		return 1;
	}
	if(str[i]==str[j])
	{
		vis[i][j] = 1;
		d[i][j] = dp(i+1,j)+dp(i,j-1)+1;//三种方式  去掉首尾 去掉首  去掉尾
		return d[i][j];
	}
	else
	{
		vis[i][j] = 1;
		d[i][j] = dp(i+1,j)+dp(i,j-1)-dp(i+1,j-1);//鸽笼 去掉首 去掉尾  减去交集
		return d[i][j];
	}
}
int main ()  
{  
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;  
    scanf("%d",&t);  
    for(int i = 0; i < M; i++) d[i][i] = 1;  
	getchar();
    while(t--)  
    {  
		gets(str);
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < M; i++) d[i][i] = 1;  
		int len = strlen(str);
		long long ans = dp(0,len-1);
        printf("%lld\n",ans);  
    }  
    return 0;  
}
