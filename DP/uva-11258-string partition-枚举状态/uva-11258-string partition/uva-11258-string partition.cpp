// uva-11258-string partition.cpp : 定义控制台应用程序的入口点。
//给出一个字符串，由0~9组成，现在可以将字符串切割成若干段，每一段便可代表一个数值，
//但是这个数值不能大于int的最大上限，问，如何切割可以使得这若干个数的和最大。

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
char str[205];
long long d[205];//前0:i位最优解
const int INF = INT_MAX; 
long long max(long long a, long long b) {  
    return a > b ? a : b;  
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
		gets(str);
		
		int len = strlen(str);
		for(int i = 1; i <= len; i++) d[i] = -INF;  
		d[0] = str[0]-'0';
		for(int i = 1;i<len;i++)
		{
			for(int j = i-1;j+1>=0&&j>=i-10;j--)//将j+1:i组成一个数 int不能超过10位
			{
				long long num = 0;
				if(str[j+1]=='0'&&i-j>1)//
					continue;
				for(int k = j+1;k<=i;k++)
					num = num*10+str[k]-'0';
				if(num>=0&&num<=INT_MAX)
				{
					if(j>=0)//还有剩余字符
						d[i] = max(d[i],d[j]+num);
					else
						d[i] = max(d[i],num);
				}
				else 
					break;
			}
		}
		printf("%lld\n",d[len-1]);
	}
	return 0;
}

