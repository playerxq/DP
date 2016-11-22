// uva-10651-pepple solitaire.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 10000;
char str[13];
int a[12];
int d[maxn];
int vis[maxn];
int get_s(int i, int j)
{
	int res = 0;
	for(int k = j;k>=i;k--)
	{
		res*=2;
		res+=a[k];
	}
	return res;
}
int get_ans(int x)
{
	if(vis[x])
		return d[x];
	int imin = 15;
	int flag = 1;
	for(int i = 0;i<12;i++)
	{
		if(x&(1<<(i))&&x&(1<<(i+1)))  
        {  
            if(i>0&&!(x&(1<<(i-1)))) {imin=min(imin,get_ans(x^(1<<(i-1)^(1<<i)^(1<<(i+1)))));flag=false;}  
            if(i+2<12&&!(x&(1<<(i+2)))) {imin=min(imin,get_ans(x^(1<<i)^(1<<(i+1)^(1<<(i+2)))));flag=false;}  
        }
	}
	if(flag)
	{
		int temp=0;  
        for(int i=0;i<12;i++)  
        {  
            if(x&(1<<i)) temp++;  
        }  
        vis[x]=1;  
        d[x]=temp;  
        return temp;
	}
	vis[x]=1;  
    d[x]=imin;  
    return imin;
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
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<12;i++)
		{
			if(str[i]=='o')
				a[i] = 1;
		}
		int s = get_s(0,11);
		int ans = get_ans(s);
		printf("%d\n",ans);
	}
	return 0;
}

