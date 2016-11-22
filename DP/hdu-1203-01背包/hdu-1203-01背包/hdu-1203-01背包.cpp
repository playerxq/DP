// hdu-1203-01背包.cpp : 定义控制台应用程序的入口点。
//:dp[j]=min(dp[j],dp[j-val[i]]*p[i])

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


int main()
{
    int n,m,i,j,val[10005];
    double dp[10005],p[10005];
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i = 1;i<=m;i++)
        {
            scanf("%d%lf",&val[i],&p[i]);
            p[i] = 1-p[i];
        }
        for(i = 0;i<=n;i++)
			dp[i] = 1.0;
        for(i = 1;i<=m;i++)
        {
            for(j = n;j>=val[i];j--)
            {
                dp[j] = min(dp[j],dp[j-val[i]]*p[i]);
            }
        }
        printf("%.1f%%\n",(1-dp[n])*100);
    }

    return 0;
}


