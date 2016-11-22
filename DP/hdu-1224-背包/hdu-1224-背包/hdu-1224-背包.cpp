// hdu-1224-背包.cpp : 定义控制台应用程序的入口点。
//

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
#define N 105
int dp[N],pre[N],a[N];
int g[N][N];
int n;
void out (int i)
{
    if (i==1)
    {
        printf("1");
        return ;
    }
    out(pre[i]);
    printf("->%d",i);
}
int main()
{
    int T,cas,i,j,m,b,e;
    scanf("%d",&T);
    for (cas=1;cas<=T;++cas)
    {
        if (cas!=1) printf("\n");
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for (i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for (i=1;i<=m;++i)
        {
            scanf("%d%d",&b,&e);
            g[b][e]=1;
        }
        a[n+1]=0;
        for (i=1;i<=n+1;++i)
        {
            for (j=1;j<i;++j)
            {
                if (g[j][i])//寻找前面可达的前驱
                {
                    if (dp[j]+a[i]>dp[i])
                    {
                        dp[i]=dp[j]+a[i];
                        pre[i]=j;
                    }
                }
            }
        }
        printf("CASE %d#\n",cas);
        printf("points : %d\n",dp[n+1]);
        printf("circuit : ");
        out(pre[n+1]);
        printf("->%d\n",1);
    }
    return 0;
}


