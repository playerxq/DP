// test-有向树k中值.cpp : 定义控制台应用程序的入口点。
//

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
int n,k;
struct node
{
	int w,dep,d;
	int cost[10][100];//cost[i][j]为以当前节点为根的子树中设置k个机构 且当前节点最近的祖先机构为j时的转移费用
	int *dis;
	struct node* parent;
	struct node* left;
	struct node* right;
};
typedef node* link;
link* subt;
link newnode()
{
	link p = new node();
	return p;
}
void visit(link t)
{
	if(t->parent)
		t->dep = t->parent->dep+1;
	t->dis = new int[t->dep+1];
	t->dis[0] = 0;
	if(t->parent)
		for(int i = 1;i<=t->dep;i++)
			t->dis[i] = t->parent->dis[i-1]+t->d;//计算t与第i个祖先点的距离
}
void preorder(link t)
{
	if(t)
	{
		visit(t);
		preorder(t->left);
		preorder(t->right);
	}
}
void sd(link t)
{
	preorder(t);
}
link findc(link q)
{
	while(q&&q->right) q = q->right;
	return q;
}
void init()//将有向树转化为2叉树
{
	int a,b,c;
	scanf("%d%d",&n,&k);
	subt = new link[n+1];
	for(int i = 0;i<=n;i++)
	{
		subt[i] = newnode();
	}
	for(int i = 1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		subt[i]->w = a;
		subt[i]->d = c;
		link p = findc(subt[b]);//找到父节点 并沿父节点右树向下
		link q = newnode();
		p->left = subt[i];//当前节点作为父节点的左节点
		p->right = q;//虚拟节点为右
		subt[i]->parent = p;
		q->parent = p;
	}
	sd(subt[0]);//前序遍历计算dis
}
void comp(link t)
{
	if(!t->left)//leaf
	{
		for(int i = 0;i<=t->dep;i++)
			t->cost[0][i] = t->dis[i]*t->w;
		for(int i = 1;i<=k;i++)//此处设置机构使得leaf没有转移费用
			for(int j = 0;j<=t->dep;j++)
				t->cost[i][j] = 0;
	}
	else
	{
		for(int i = 0;i<=k;i++)
		{
			for(int j = 0;j<=t->dep;j++)
			{
				if(i)
					t->cost[i][j] = t->cost[i-1][0];//当前节点设置机构
				else
					t->cost[i][j] = INT_MAX;
				for(int a = 0;a<=i;a++)
				{
					int temp = t->left->cost[a][j+1]+t->right->cost[i-a][j+1]+t->w*t->dis[j];
					if(t->cost[i][j]>temp)
						t->cost[i][j]=temp;
				}
			}
		}
	}
}

void postorder(link t)
{
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		comp(t);
	}
}
int solution()//后续遍历计算结果
{
	postorder(subt[0]);
	return subt[0]->cost[k][0];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	cout<<solution();
	return 0;
}

