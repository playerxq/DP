// uva-590-always on the run.cpp : 定义控制台应用程序的入口点。
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
#define N 15  
#define K 1005  
#define INF 0x7fffffff  
int n, k, d, dp[K][N], a[N][N][K];  
int main ()  
{  
    int tt = 0;  
    while(scanf("%d %d",&n,&k),n+k)  
    {  
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)  
        {  
            if(i==j) continue;  
            scanf("%d",&d);  
            a[i][j][0] = d;  //i->j的天数周期
            for(int l = 1; l <= d; l++) scanf("%d",&a[i][j][l]);  //每天价格
        }  
        memset(dp,-1,sizeof(dp));  
        dp[0][1] = 0;  
        for(int i = 1; i <= k; i++)  
        {  
            for(int j = 1; j <= n; j++)  //i个航班到达j  第i-1个航班到达l 为d[i-1][l]+G[l][j]
            {  
                int &ans = dp[i][j];  
                ans = INF;  
                for(int l = 1; l <= n; l++)  //i-1个航班到达l
                {  
                    if(l==j) continue;  
                    if(dp[i-1][l]==-1) continue;  
                    int num = (i-1)%a[l][j][0]+1;  //已用天数i-1  周期a[][][0] 下一天
                    if(num==0) num = a[l][j][0];  
                    int value = a[l][j][num];  
                    if(value==0) continue;  
                    ans = ans<dp[i-1][l]+value?ans:dp[i-1][l]+value;  
                }  
                if(ans==INF) ans = -1;  
            }  
        }  
        printf("Scenario #%d\n",++tt);  
        if(dp[k][n]==-1) printf("No flight possible.\n\n");  
        else printf("The best flight costs %d.\n\n",dp[k][n]);  
    }  
    return 0;  
} 

