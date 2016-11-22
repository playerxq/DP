// uva-10405-lcs.cpp : 定义控制台应用程序的入口点。
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
char s1[1001];
char s2[1001];
int d[1001][1001];
int lcs()
{
	memset(d,0,sizeof(d));
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int f = 0;
	for(int i = 0;i<len1;i++)
	{
		d[i][0] = 0;
	}
	for(int i = 0;i<len2;i++)
	{
		d[0][i] = 0;
	}
	for(int i = 1;i<=len1;i++)
	{
		for(int j = 1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				d[i][j] = d[i-1][j-1]+1;
			else
			{
				d[i][j]=(d[i-1][j]>d[i][j-1])?d[i-1][j]:d[i][j-1];
			}
		}
	}
	return d[len1][len2];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(gets(s1))
	{
		gets(s2);
		printf("%d\n",lcs());
	}
	return 0;
}

