// hdu-1208-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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


int n,i,j,k;
__int64 dp[40][40];
int map[40][40];
char s[40];

int main()
{
    while(~scanf("%d",&n),n+1)
    {
        for(i = 0; i<n; i++)
        {
            scanf("%s",s);
            for(j = 0; j<n; j++)
            {
                map[i][j] = s[j]-'0';
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                if(!map[i][j] || !dp[i][j])
                    continue;
                if(i+map[i][j]<n)//��Խ��
                    dp[i+map[i][j]][j]+=dp[i][j];
                if(j+map[i][j]<n)
                    dp[i][j+map[i][j]]+=dp[i][j];
            }
        }
        printf("%I64d\n",dp[n-1][n-1]);
    }
    return 0;
}


