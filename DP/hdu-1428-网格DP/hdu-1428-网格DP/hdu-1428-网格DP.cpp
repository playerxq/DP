// hdu-1428-网格DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N=55;  
const int inf=123456789;  
  
int n,map[N][N],dis[N][N];  
__int64 dp[N][N];  
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};  
struct node1
{
	int x,y,dis;
	bool friend operator < (struct node1 a,struct node1 b)//升序排序
	{
		return b.dis<a.dis;
	}
};
void bfs1()
{
	int i,flag[N][N];  
    node1 now,next;  
    priority_queue<struct node1> q;  //dis小的优先级高 先出队列
  
    memset(flag,0,sizeof(flag));  
    now.x=n-1;  
    now.y=n-1;  
    now.dis=map[now.x][now.y];  
    q.push(now);  
  
    while(!q.empty())  
    {  
        now=q.top();  
        q.pop();  
        if(flag[now.x][now.y])  continue;  
        flag[now.x][now.y]=1;  
        for(i=0;i<4;i++)  
        {  
            next.x=now.x+dir[i][0];  
            next.y=now.y+dir[i][1];  
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=n)  continue;  
            if(flag[next.x][next.y])    continue;  
            if(dis[now.x][now.y]+map[next.x][next.y] >= dis[next.x][next.y]) continue;  
            next.dis=dis[next.x][next.y]=dis[now.x][now.y]+map[next.x][next.y];  
            q.push(next);  
        }  
    }
}
struct node2  
{  
    int x,y,dis;  
    bool friend operator<(node2 n1,node2 n2){  //降序
        return n1.dis<n2.dis;  
    }  
};  
void bfs2()  
{  
    int i,flag[N][N];  
    node2 now,next;  
    priority_queue<struct node2> q;  //dis大的优先级高 先出队列
  
    memset(flag,0,sizeof(flag));  
    now.x=0;  
    now.y=0;  
    now.dis=dis[0][0];  
    q.push(now);  
    flag[0][0]=1;  
    while(!q.empty())  
    {  
        now=q.top();  
        q.pop();  
        for(i=0;i<4;i++)  
        {  
            next.x=now.x+dir[i][0];  
            next.y=now.y+dir[i][1];  
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=n)  continue;  
            next.dis=dis[next.x][next.y];  
            if(next.dis < now.dis)  
            {  
                dp[next.x][next.y]+=dp[now.x][now.y];  
                if(!flag[next.x][next.y])   {q.push(next);flag[next.x][next.y]=1;}  
            }  
        }  
    }  
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,l;  
    while(scanf("%d",&n)!=-1)  
    {  
        for(i=0;i<n;i++)  
        for(l=0;l<n;l++)  
        {  
            scanf("%d",&map[i][l]);  
            dp[i][l]=0;  
            dis[i][l]=inf;  
        }  
        dp[0][0]=1;  
        dis[n-1][n-1]=map[n-1][n-1];  
        bfs1();  
        bfs2();  
        printf("%I64d\n",dp[n-1][n-1]);  
    } 
}

