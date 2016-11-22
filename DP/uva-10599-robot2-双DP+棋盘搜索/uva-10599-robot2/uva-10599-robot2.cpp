// uva-10599-robot2.cpp : 定义控制台应用程序的入口点。
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
int a[105][105];
int r,col;
int ncase = 1;
long long d[105][105];//得到G数目
long long c[105][105];//路数
int ans[105*105],top;
long long dp(int i, int j)//计算垃圾最多的路径上的垃圾数目
{
	if(d[i][j]!=-1)
		return d[i][j];
	if(i==r&&j==col)
	{
		return d[r][col] = a[r][col];
	}
	d[i][j] = 0;
	if(i+1<=r)
		d[i][j]=max(d[i][j],a[i][j]+dp(i+1,j));
    if(j+1<=col)
		d[i][j]=max(d[i][j],a[i][j]+dp(i,j+1));
	return d[i][j];
}
long long dp_c(int i, int j)//路径数  注意(i,j)与(x,y)路径上没有垃圾的话  则若干路径算一条
{
	if(c[i][j]!=-1)
		return c[i][j];
	if(d[i][j]==a[i][j])//(i,j)到终点的路径上没有其他的垃圾  故只算一条路径
		return c[i][j] = 1;
	c[i][j] = 0;
	for(int dx = 0;i+dx<=r;dx++)//从(i,j)寻找下一个垃圾点  且此垃圾点应在最多垃圾路径上
	{
		for(int dy = 0;dy+j<=col;dy++)
		{
			if(!dx&&!dy)
				continue;
			int x=i+dx,y=j+dy;
			if(a[x][y]&&d[i][j]==d[x][y]+a[i][j])//下一个垃圾点在最多垃圾点路径上，中间空格不算路径
				c[i][j]+=dp_c(x,y);
		}
	}
	return c[i][j];
}

void print(int i,int j)//(i,j)处有垃圾  并打印后续路径
{
    if(a[i][j])
    {
        int dep=d[1][1]-d[i][j];
        ans[dep]=(i-1)*col+j;
    }
    if(d[i][j]==a[i][j])
		return ;
    bool ok=true;
    for(int dx=0;i+dx<=r&&ok;dx++)
		for(int dy=0;j+dy<=col&&ok;dy++)
		{
			if(!dx&&!dy)
				continue;
			int x=i+dx,y=j+dy;
			if(a[x][y]&&d[i][j]==d[x][y]+a[i][j])
			{
				print(x,y);//从下一个垃圾点打印
				ok=false;
			}
		}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&r,&col),r!=-1||col!=-1)
    {
        memset(a,0,sizeof(a));
        memset(d,-1,sizeof(d));
        memset(c,-1,sizeof(c));
        for(;;)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x+y==0)
				break;
            a[x][y]++;
        }
        top=dp(1,1);
        dp_c(1,1);
        print(1,1);
        printf("CASE#%d: %I64d %I64d",ncase++,d[1][1],c[1][1]);
        for(int i=0;i<top;i++)
			printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}

