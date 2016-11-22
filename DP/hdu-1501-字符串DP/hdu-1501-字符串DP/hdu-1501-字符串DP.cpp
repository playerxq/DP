// hdu-1501-字符串DP.cpp : 定义控制台应用程序的入口点。
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
int len1,len2,len3;
char str1[201],str2[201],str3[402];
bool dfs(int i, int j, int k)
{
	if(k<0&&i<0&&j<0)
		return 1;
	else if(k<0)
		return 0;
	else if(k+1!=(i+j+2))
	{
		return 0;
	}
	else
	{
		bool flag = false;
		if(i>=0&&str3[k]==str1[i])
			flag |= dfs(i-1,j,k-1);
		if(flag==false&&j>=0&&str3[k]==str2[j])
			flag |= dfs(i,j-1,k-1);
		return flag;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1;i<=T;i++)
	{
		scanf("%s",str1);
		scanf("%s",str2);
		scanf("%s",str3);
		len1 = strlen(str1);
		len2 = strlen(str2);
		len3 = strlen(str3);
		if(dfs(len1-1,len2-1,len3-1))
			printf("Data set %d: yes\n",i);
		else
			printf("Data set %d: no\n",i);
	}
}

