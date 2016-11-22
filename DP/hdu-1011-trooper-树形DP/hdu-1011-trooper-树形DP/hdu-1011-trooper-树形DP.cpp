// hdu-1011-trooper-树形DP.cpp : 定义控制台应用程序的入口点。
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
const int N = 105;
int head[N],dp[N][N],vis[N],bug[N],p[N];
int n,m,len;
struct node
{
	int now,_next;
}tree[N];
void add(int x, int y)//x,y之间有边 y是x后继
{
	tree[len].now = y;
	tree[len]._next=head[x];
	head[x]=len++;
}
void dfs(int root)
{
	vis[root]=1;
	int cost = (bug[root]+19)/20;
	for(int i = cost;i<=m;i++)
	{
		dp[root][i]=p[root];
	}
	for(int i = head[root];i!=-1;i=tree[i]._next)
	{
		int son = tree[i].now;
		if(vis[son]==0)
		{
			dfs(son);
			for(int j = m;j>=cost;j--)//j个人留在root
			{
				for(int k = 1;j+k<=m;k++)//达到后继有k个人
				{
					if(dp[son][k])
					{
						dp[root][j+k]=max(dp[root][j+k],dp[root][j]+dp[son][k]);
					}
				}
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n>=0&&m>=0)
	{
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));
		len = 0;
		for(int i = 1;i<=n;i++)
		{
			scanf("%d%d",&bug[i],&p[i]);
		}
		for(int i = 1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		if(!m)
		{
			printf("0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		dfs(1);
		printf("%d\n",dp[1][m]);
	}
}

