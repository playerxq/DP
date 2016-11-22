// uva-10280-old wine into bottle.cpp : 定义控制台应用程序的入口点。
//现在有L升酒，以及n种酒瓶，现在给出每种酒瓶的最小容量和最大容量，
//每种酒瓶可以使用无限多次，问，怎样装酒，可以使得剩下的酒（即未能装进酒瓶中的酒）最少


/*
对于一类瓶子，我们不妨设用k个瓶子去装酒，那么能够完全装下的范围就是[k*min,k*max]，
随着k的增大，我们发现所有相邻区间的左端点的间距是固定的，同时区间的长度又在不断增加，
于是我们猜想，到某一刻时，后面的区间相互之间会有交集，这样剩下的各个区间就会覆盖掉后面所有的整数。
我们设刚开始产生交集的区间为第k个，这样有k*max>=(k+1)*min，解得k>=min/(max-min)，
而当酒量x>=k*min的时候，就一定能全被装进去，这样就有x>=min*min/(max-min)。

剩下的工作就是把瓶子按不同的容积拆成max-min+1个瓶子，然后做完全背包的dp
*/
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
#define N 450000
int d[N];
int vis[N];
int bottle[N];
int v,n;
typedef struct PPP
{
	int mina;
	int maxa;
} pp;
pp a[101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&v);
		v = v*1000;
		scanf("%d",&n);
		int k = 0x3f3f3f3f;
		for(int i = 0;i<n;i++)//取最小的可以被全装的酒的界限
		{
			scanf("%d%d",&a[i].mina,&a[i].maxa);
			if(k>=a[i].mina*a[i].mina/(a[i].maxa-a[i].mina))
				k=a[i].mina*a[i].mina/(a[i].maxa-a[i].mina);
		}
		if(v>=k)
		{
			printf("0\n");  
            if(T)  
				printf("\n"); 
		}
		else
		{
			memset(d,0,sizeof(d));
			memset(vis,0,sizeof(vis));
			int cnt = 0;
			for(int i = 0;i<n;i++)//得到所有的子瓶子
			{
				for(int k = a[i].mina;k<=a[i].maxa;k++)
				{
					if(vis[k]==0)
					{
						vis[k] = 1;
						bottle[cnt++] = k;
					}
				}
			}
			for(int i = 0;i<cnt;i++)//做完全背包
			{
				for(int j = bottle[i];j<=v;j++)
				{
					d[j] = max(d[j],d[j-bottle[i]]+bottle[i]);
				}
			}
			printf("%d\n",v-d[v]);
			if(T)  
				printf("\n"); 
		}
	}
	return 0;
}

