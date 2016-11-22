// uva-825-walk on save side.cpp : 定义控制台应用程序的入口点。
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
int W,N;
int map[105][105];
int vis[105][105];
int d[105][105];
int next[2][2]={0,1,1,0}; 
void fun(int pos,char *str)  
{  
    int len=strlen(str),num=0;  
    for(int i=0;i<len;i++)  
    {  
        if(isdigit(str[i]))  
        {  
            num=num*10+str[i]-'0';  
        }  
        else  
        {  
            if(num!=0) map[pos][num]=1;  
            num=0;  
        }  
    }  
    if(num!=0) map[pos][num]=1;  
} 
int dfs(int x, int y)
{
	if(vis[x][y])
		return d[x][y];
	if(x==W&&y==N)
	{
		d[x][y] = 1;
		vis[x][y] = 1;
		return 1;
	}
	for(int i = 0;i<2;i++)
	{
		int nextx = x+next[i][0];
		int nexty = y+next[i][1];
		if(map[nextx][nexty]==0&&nextx>0&&nextx<=W&&nexty>0&&nexty<=N)
		{
			d[x][y] += dfs(nextx,nexty);
		}
	}
	vis[x][y] = 1;
	return d[x][y];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&W,&N);
		memset(map,0,sizeof(map));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		char str[100];
		for(int i = 0;i<W;i++)
		{
			int temp;
			scanf("%d",&temp);
			gets(str);
			fun(temp,str);
			str[0]='\0';
		}
		int ans = dfs(1,1);
		printf("%d\n",ans);
		if(T)
			printf("\n");
	}
	return 0;
}

