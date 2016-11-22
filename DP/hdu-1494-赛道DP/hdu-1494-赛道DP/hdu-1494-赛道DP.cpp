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
#define MAX 10010
#define INF 1000000000
#define MIN(a,b) (a)<(b)?(a):(b)


int n,m,tot,dp[MAX][16];
int A[MAX],B[MAX];


int main()
{
    int i,j,k,t,add,next;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&m) != EOF) {

        tot = n * m;
        for (i = 0; i < n; ++i)
            scanf("%d",&A[i]);
        for (j = 0; j < n; ++j)
            scanf("%d",&B[j]);
        for (i = 0; i < tot; ++i)
            A[i] = A[i%n],B[i] = B[i%n];
        
        
        for (i = 0; i <= 15; ++i)
            for (j = 0; j <= tot; ++j)
                dp[j][i] = INF;
        dp[1][1] = A[0];
        
        
        for (i = 1; i < tot; ++i)
            for (j = 0; j < 15; ++j) {//3个满格状态  即2个满状态转化为加速卡  还剩余一个满状态

                k = j + 1;
                if (k == 15) k = 10;//当满3个状态时  清掉第三个
                dp[i+1][k] = MIN(dp[i][j]+A[i],dp[i+1][k]);
                if (j >= 5) dp[i+1][j-5] = MIN(dp[i][j]+B[i],dp[i+1][j-5]);//至少一个满状态 即至少一个加速卡  消耗掉 即剩余j-5的状态
            }


        int ans = INF;
        for (i = 0; i < 15; ++i)
            ans = MIN(ans,dp[tot][i]);
        printf("%d\n",ans);
    }
}