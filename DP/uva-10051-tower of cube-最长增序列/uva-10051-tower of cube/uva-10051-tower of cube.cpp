// uva-10051-tower of cube.cpp : 定义控制台应用程序的入口点。
//最长增序列,枚举所有摆放形式

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
typedef struct _box
{
	int id;//also the weight
	int top;
	int bottom;
	int face;
} box;
int a[6];
box cube[3001];
int f[3001];
int pre[3001];
int cnt;
int maxn,max_index;
void fun(int index,int id, int face, int top,int bottom)
{
	cube[index].id = id;
	cube[index].face = face;
	cube[index].bottom = bottom;
	cube[index].top = top;
}
int long_path()//最长递增子串
{
	for(int i = 0;i<cnt;i++)
		f[i] = 1;
	for(int i = 1;i<cnt;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(cube[i].id>cube[j].id&&cube[i].top==cube[j].bottom&&f[i]<f[j]+1)//j可以放到i前面
			{
				f[i] = f[j]+1;
				pre[i] = j;
			}
		}
	}
	maxn = 1;
	max_index = -1;
	for(int i = 0;i<cnt;i++)
		if(f[i]>maxn)
		{
			maxn = f[i];
			max_index = i;
		}
	return maxn;
}
int rev(int i)//对面
{
	if(i==0)
		return 1;
	if(i==1)
		return 0;
	if(i==2)
		return 3;
	if(i==3)
		return 2;
	if(i==4)
		return 5;
	if(i==5)
		return 4;
}
void output(int max_index)
{
	if(max_index==-1)
		return;
	output(pre[max_index]);
	printf("%d ",cube[max_index].id);
	switch(cube[max_index].face)
	{
	case 0:
		printf("front\n");
		break;
	case 1:
		printf("back\n");
		break;
	case 2:
		printf("left\n");
		break;
	case 3:
		printf("right\n");
		break;
	case 4:
		printf("top\n");
		break;
	case 5:
		printf("bottom\n");
		break;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int ncase = 1;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		if(ncase>1)
			printf("\n");
		cnt = 0;
		memset(cube,0,sizeof(cube));
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<6;j++)//6个面颜色
			{
				scanf("%d",&a[j]);
			}
			for(int j = 0;j<6;j++)//所有旋转摆放方式
			{
				fun(cnt,i+1,j,a[j],a[rev(j)]);
				cnt++;
			}
		}
		memset(f,0,sizeof(f));
		memset(pre,-1,sizeof(pre));
		int ans = long_path();
		printf("Case #%d\n",ncase++);
		printf("%d\n",ans);
		if(max_index==-1)
		{
			printf("1 front\n");
		}
		else
			output(max_index);
	}
	return 0;
}

