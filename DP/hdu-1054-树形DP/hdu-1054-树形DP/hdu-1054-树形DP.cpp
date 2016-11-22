// hdu-1054-树形DP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[1505][2],f[1505],ans,n;
int son[1505][1505],size[1505];
int dfs(int pos,int val)
{
    if(dp[pos][val]!=INT_MIN)
        return dp[pos][val];
    int sum=val;
    for(int i=0;i<size[pos];i++)
    {
        if(val==1)
            sum+=min(dfs(son[pos][i],0),dfs(son[pos][i],1));
        else sum+=dfs(son[pos][i],1);//当前节点不选，则子节点必须要选
    }
    return dp[pos][val]=sum;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            f[i]=i;
            dp[i][1]=dp[i][0]=INT_MIN;
        }
        for(int i=0;i<n;i++)
        {
            int x,m;
            scanf("%d:(%d)",&x,&m);
            size[x]=m;
            for(int j=0;j<size[x];j++)
            {
                scanf("%d",&son[x][j]);
                f[son[x][j]]=x;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(f[i]==i)
            {
                ans=min(dfs(i,0),dfs(i,1));
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

