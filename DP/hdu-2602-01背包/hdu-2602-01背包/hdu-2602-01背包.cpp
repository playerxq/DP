// hdu-2602-01背包.cpp : 定义控制台应用程序的入口点。
//dp[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。
//则其状态转移方程便是：
//dp[i][v]=max{dp[i-1][v],dp[i-1][v-cost[i]]+value[i]}

#include "stdafx.h"
#include<iostream>
using namespace std;
int dp[1000][1000];

int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    int t,n,v,i,j;
    int va[1000],vo[1000];
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(i=1;i<=n;i++)
            cin>>va[i];
        for(i=1;i<=n;i++)
            cin>>vo[i];
        memset(dp,0,sizeof(dp));//初始化操作
         for(i=1;i<=n;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(vo[i]<=j)//表示第i个物品将放入大小为j的背包中
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);//第i个物品放入后，那么前i-1个物品可能会放入也可能因为剩余空间不够无法放入
                else //第i个物品无法放入
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][v]<<endl;
    }
    return 0;
}

