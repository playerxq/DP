// uva-10913-walking on a grid.cpp : 定义控制台应用程序的入口点。
//有一个大小有N（最多75）的方格，要你从（1，1）走到（n,n）
//你只有三个方向，左、右、下。不能走出方格。
//一个方格只能走一次。你要保证你的路径上的格子的和最大。
//你最多只能走k(最多为5)个负权值的格子，从起点到终点

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
#define LL long long  
#define INF -((LL)1<<60)
int n,k;
long long a[80][80];
long long d[80][80][7][3];
int vis[80][80][7][3];
int flag[80][80];
int dir[3][2]={{0,1},{1,0},{0,-1}}; //下 右 上
int ok(int i, int j)
{
	if(i>=1&&i<=n&&j>=1&&j<=n)
		return 1;
	return 0;
}
long long dp(int x, int y, int z, int r)//z: 剩余负数步数+1  保持索引正值性 z>=1才能继续走
{
	int& fff = vis[x][y][z][r];
	long long& ans = d[x][y][z][r];
	if(fff)
		return ans;
	else if((x==n&&y==n)||(z==0))//到达终点  或者负数格子已经走完 
	{
		fff = 1;
		if(z==0)
			return ans = INF;//connot reach
		return ans = a[x][y];
	}
	else
	{
		ans = INF;
		for(int i=0;i<3;i++)  
        {  
            int xx=x+dir[i][0],yy=y+dir[i][1],t=0;  
            if(a[x][y]<0) t=-1;  
            if(ok(xx,yy)&&!flag[xx][yy])  //格子未走过
            {  
                if((r==0&&i==2)||(r==2&&i==0)) continue;  //不是原方向返回
                flag[xx][yy]=1;  
                LL temp=dp(xx,yy,z+t,i);  
                if(temp!=INF) ans=max(ans,temp+a[x][y]);  
                flag[xx][yy]=0;  
            }  
        }
		fff = 1;
		return ans;
	}

}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&n,&k))
	{
		if(n+k==0)
			break;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				scanf("%lld",&a[i][j]);
		if(a[n][n]<0) k--;
		memset(d,INF,sizeof(d));
		memset(vis,0,sizeof(vis));
		LL res=dp(1,1,k+1,1);  
        printf("Case %d: ",ncase++);  
        if(res!=INF) printf("%lld\n",res);  
        else printf("impossible\n");
	}
	return 0;
}

