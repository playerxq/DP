// test-因子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
/*
int d[100];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	d[1] = 1;
	for(int i = 2;i<=n;i++)
	{
		for(int j = 2;j<=i;j++)
			if(i%j==0)
				d[i]+=d[i/j];
	}
	printf("%d",d[n]);
	return 0;
}
*/
/*
#define MAXN 50
int G[MAXN][MAXN];
int v,e;
int x[MAXN];
int bestx[MAXN];
int cn;
int best;
void init()
{
	scanf("%d",&v);
	for(int i = 1;i<=v;i++)
	{
		for(int j = 1;j<=v;j++)
			scanf("%d",&G[i][j]);
		x[i]=0;
		bestx[i]=0;
	}
	best=cn=0;
}
void backtrack(int i)
{
	if(i>v)
	{
		if(cn>best)
		{
			for(int j = 1;j<=v;j++)
				bestx[j]=x[j];

			best=cn;
		}
		return;
	}
	int ok = 1;
	for(int j = 1;j<i;j++)
	{
		if(x[j]&&(G[i][j]==0&&G[j][i]==0))
		{
			ok = 0;
			break;
		}
	}
	if(ok)
	{
		x[i]=1;
		cn++;
		backtrack(i+1);
		x[i]=0;
		cn--;
	}
	if(cn+v-i>best)
	{
		x[i]=0;
		backtrack(i+1);
	}
}
void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	backtrack(1);
	for(int i = 1;i<=v;i++)
	{
		if(bestx[i])
			printf("%d ",i);
	}
	printf("\n");
	printf("%d\n",best);
}
*/
#define MAXN 50
int v,e;
int bestn,cn;
int G[MAXN][MAXN];
int x[MAXN];
int bestx[MAXN];
void init()
{
	scanf("%d",&v);
	for(int i = 1;i<=v;i++)
	{
		for(int j = 1;j<=v;j++)
			scanf("%d",&G[i][j]);
		x[i]=0;
		bestx[i]=0;
	}
	bestn=cn=0;
}
struct BBNode
{
	BBNode *parent; //指向父结点的指针
	bool LChild; //左儿子结点标志
};
struct CliqueNode //定义优先队列类型为CliqueNode
{
	int cnum; //当前团的顶点数
	int un; //当前团最大顶点数的上界
	int level; //结点在子集空间树种所处的层次
	BBNode *p; //指向活结点在子集树中相应结点的指针
	bool operator<(const CliqueNode &b) const //<号重载建立大根堆
	{
		if (b.un>un) return true;
		if (b.un==un&& b.cnum>cnum) return true;
		else return false;
	}
};
void BBMaxClique()
{
	BBNode *E=new(BBNode);
	int j,i=1;
	int cnum=0;
	int OK=1;
	priority_queue<CliqueNode> Q;
	E->LChild=false; //初始化
	E->parent=NULL;
	while(i!=v+1)
	{
		OK = 1;
		BBNode *B=E;
		for(j=i-1;j>0;B=B->parent,j--)
		{
			if(B->LChild&&G[i][j]==0&&G[j][i]==0)
			{
				OK = 0;
				break;
			}
		}
		if(OK)
		{
			CliqueNode *D=new(CliqueNode);
			D->p=new(BBNode);
			if(cnum+1>bestn)bestn=cnum+1;
			D->cnum=cnum+1;
			D->level=i+1;
			D->p->LChild=true;
			D->p->parent=E;
			D->un=cnum+1+v-i;
			Q.push(*D); //进队列
		}
		if(cnum+v-i>bestn)
		{
			CliqueNode *D=new(CliqueNode);
			D->p=new(BBNode);
			D->cnum=cnum;
			D->level=i+1;
			D->p->LChild=false;
			D->p->parent=E;
			D->un=cnum+v-i;
			Q.push(*D); //进队列
		}
		CliqueNode N;
		N=Q.top();
		Q.pop();
		E=N.p;
		cnum=N.cnum;
		i = N.level;
	}
	for(j=v;j>0;j--) //保存最优解
	{
		bestx[j]=E->LChild;
		E=E->parent;
		bestn=cnum;
	}
}
void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	BBMaxClique();
	for(int i = 1;i<=v;i++)
	{
		if(bestx[i])
			printf("%d ",i);
	}
	printf("\n");
	printf("%d\n",bestn);
}