// uva-10817-headmaster headache.cpp : 定义控制台应用程序的入口点。
//有n个教师和m个求职者。已知每人的工资和能交的课程集合，
//要求支付最少的工资使得每门课都至少有两名教师教学。在职教师必须招聘
//用16位2进制数来表示。2进制中从右往左数，前8为表示有1位老师教该门课程，
//后8为表示有2位老师教（该位-8）的课程
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
#define INF 0x3f3f3f3f

#define N (1<<16)+5//低8位表示一个教室上i课程 高8位2个教室上第i个课程
int vis[N][105];
int d[N][105];//d[i][j]第j个教师是否雇佣后的状态为i
int v[105];
int s,m,n,st,T;
int lesson[105][20];
int dp(int st, int i)
{
	if(vis[st][i])
		return d[st][i];
    vis[st][i]=1;
 
    if(st==T)//到达目标
		return d[st][i]=0;
    if(i==n)
		return INF;
    int next=st,&top=lesson[i][0];
    for(int j=1;j<top;j++)//雇佣第i个人对状态产生的改变
    {
        int y=lesson[i][j];//第j个课程y
        if((1<<(s+y))&next)//已经有2个人教
			continue;
        if((1<<y)&next)
			next=next-(1<<y)+(1<<(s+y));
        else
			next=next+(1<<y);
    }
    if(next!=st)//有雇佣必要
		d[st][i]=min(d[st][i],dp(next,i+1)+v[i]);
    d[st][i]=min(d[st][i],dp(st,i+1));//不雇佣
    return d[st][i];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&s,&m,&n),s+m+n)
	{
		st=0;
		int ans = 0;
        char t[100];
        memset(vis,0,sizeof(vis));
        memset(d,INF,sizeof(d));
		for(int i = 0;i<m;i++)//每个教师的课程状态
		{
			int x,y;
            scanf("%d",&x);
            ans+=x;
            gets(t);
            int k=strlen(t);
            for(int j=0;j<k;j++)
            {
                sscanf(t+j,"%d",&y);
                y--;//已教课程
                for(;isdigit(t[j]);++j);
                ++j;//skip space
                if(1<<(s+y)&st)//2个
					continue;
                if(1<<y&st)//已经有一个教了
					st=st-(1<<y)+(1<<(s+y));
                else
					st=st+(1<<y);
            }
		}
		for(int i = 0;i<n;i++)//
		{
			scanf("%d",&v[i]);
			int& top = lesson[i][0] = 1;//第i个人的课程数
            gets(t);
            int k=strlen(t);
            for(int j=0;j<k;j++)
            {
                sscanf(t+j,"%d",&lesson[i][top++]);
                lesson[i][top-1]--;
                for(;isdigit(t[j]);++j);
                ++j;//skip space
            }
		}
		T=0;
        for(int i=s;i<2*s;i++)//目标  每个课2个人  高位置一
			T+=(1<<i);
        printf("%d\n",ans+dp(st,0));
	}
	return 0;
}

