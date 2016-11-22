// uva-10739-string palindrome.cpp : �������̨Ӧ�ó������ڵ㡣
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
char str1[1001];
int d[1001][1001];
int vis[1001][1001];
int min(int a, int b,int c)
{
	int t = a<b?a:b;
	return t<c?t:c;
}
int get_ans(int i, int j)
{
	if(vis[i][j])
		return d[i][j];
	if(i>=j)
	{
		vis[i][j] = 1;
		d[i][j] = 0;
		return 0;
	}
	if(str1[i]==str1[j])
	{
		d[i][j] = get_ans(i+1,j-1);
		vis[i][j] = 1;
		return d[i][j];
	}
	else
	{
		d[i][j] = min(get_ans(i+1,j-1),get_ans(i+1,j),get_ans(i,j-1))+1;//ɾ��s[i] ����ɾ��s[j]��������ͬʱɾ��
		vis[i][j] = 1;
		return d[i][j];
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 1;
	getchar();
	while(T--)
	{
		gets(str1);
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		int ans = get_ans(0,strlen(str1)-1);
		printf("Case %d: %d\n",ncase++,ans);
	}
	return 0;
}

