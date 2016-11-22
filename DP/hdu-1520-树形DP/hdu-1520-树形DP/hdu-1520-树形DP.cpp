// hdu-1520-树形DP.cpp : 定义控制台应用程序的入口点。
//dp[i][1]表示第i个参与者参加了，dp[i][0]表示第i个参与者没有参加。
//状态转移方程就是dp[i][1]=dp[i][1]+dp[i-1][0]，dp[i][0]=dp[i][0]+Max(dp[i-1][0],dp[i-1][1])

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

#define N 6005  
struct node 
{ 
    int pa,son; 
    int next; //兄弟
}point[N];
int dp[N][2],list[N],flag[N],value[N]; 
int pos; 
int Max(int x,int y) 
{ 
    return x>y?x:y; 
} 
void add(int pa,int son) //pos位置节点的父节点是pa 兄弟节点在list中
{ 
    point[pos].pa=pa; 
    point[pos].son=son; 
    point[pos].next=list[pa];//成为pa子节点。  next指向本层兄弟
    list[pa]=pos++; 
    return ; 
} 
void dfs(int root) 
{ 
    if(list[root]==-1) 
    { 
        dp[root][1]=value[root]; 
        dp[root][0]=0; 
        return ; 
    } 
    int now=list[root]; //当前root第一个子节点
	//遍历root的每个子节点
    dp[root][0]=0; 
    dp[root][1]=value[root]; 
    while(now!=-1) 
    { 
        dfs(point[now].son); //探查子节点
        dp[root][1]+=dp[point[now].son][0];//
        dp[root][0]+=Max(dp[point[now].son][1],dp[point[now].son][0]);//
        now=point[now].next;//  now 的兄弟
    } 
    return ; 
} 
 
int main() 
{ 
    int i,n; 
    while(scanf("%d",&n)!=EOF) 
    { 
        for(i=1;i<=n;i++) 
            scanf("%d",&value[i]);//记录每一个点的值  
        int a,b; 
        pos=0; 
        memset(list,-1,sizeof(list)); 
        memset(flag,0,sizeof(flag)); 
        while(scanf("%d%d",&a,&b),a+b) 
        { 
            add(b,a);//将边加入树中  
            flag[a]=1;//记录a有父节点，不可能是祖节点。  
        } 
        a=1; 
        while(flag[a]==1) 
            a++;//找到根  
        dfs(a); 
        printf("%d\n",Max(dp[a][0],dp[a][1])); 
    } 
    return 0; 
} 
