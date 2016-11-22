// uva-11151-longest palindrome.cpp : 定义控制台应用程序的入口点。
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
char str[1001];
int vis[1001][1001];
int d[1001][1001];
int dp(int i, int j)
{
	if(vis[i][j])
		return d[i][j];
	if(i>=j)
	{
		vis[i][j] = 1;
		d[i][j] = 0;
		return 0;
	}
	if(str[i]==str[j])
	{
		d[i][j] = dp(i+1,j-1);
		vis[i][j] = 1;
		return d[i][j];
	}
	d[i][j] = 1+min(dp(i+1,j),dp(i,j-1));
	vis[i][j] = 1;
	return d[i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		gets(str);
		int ans = dp(0,strlen(str)-1);
		int ans_a = strlen(str)-ans;
		printf("%d\n",ans_a);
	}
	return 0;
}

