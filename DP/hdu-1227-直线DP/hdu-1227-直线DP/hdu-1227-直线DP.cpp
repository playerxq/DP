// hdu-1227-直线DP.cpp : 定义控制台应用程序的入口点。
//dp[i][j]表示从第一个快餐店到第i个店，中间安排了j个原料站，而且第i个店安排了原料站的最短距离和
//dp[i][j]=max{dp[k][j-1]+w[i,k]},0<=k<i w(i,k)为分别在i,k处放置原料站，中间没有时产生的和
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 2000000000

int a[205];
int w[205][205];
int dp[205][35];

int main()
{
    int i,j,n,m,k,ans,s,cnt=1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        if (n==0 && m==0) break;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=n-1;i>=0;i--)
        {
            a[i]=a[i]-a[0]+1;//距离
        }
        for (i=0;i<n;i++)//(i,j)之间没有原料站时的耗费
        {
            for(j=i;j<n;j++)
            {
                w[i][j]=0;
                for (k=i;k<=j;k++)//遍历中间每个点
                {
                    w[i][j]+=min(a[k]-a[i],a[j]-a[k]);//取较近的
                }
            }
        }
		//只设置一个
        for (i=0;i<n;i++)
        {
            for (j=0;j<=i;j++)//0:i产生的和
            {
                dp[i][1]+=a[i]-a[j];
            }
        }
        for (j=2;j<=m;j++)
        {
            for (i=j-1;i<n;i++)
            {
                dp[i][j]=INF;
                for (k=j-2;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+w[k][i]);
                }
            }
        }
        printf("Chain %d\n",cnt++);
        printf("Total distance sum = ");
        ans=INF;
        for (i=0;i<n;i++)
        {
            s=0;
            for (j=i+1;j<n;j++)
            {
                s+=a[j]-a[i];
            }
            ans=min(ans,s+dp[i][m]);
        }
        printf("%d\n\n",ans);
    }
    return 0;
}


