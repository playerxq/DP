// hdu-1513-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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

char s1[5005],s2[5005];
int dp[2][5005],n;

void LCS()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i = 1;i<=n;i++)
    {
        for(j = 1;j<=n;j++)
        {
            int x = i%2;//���ù������� ԭ����LCS��ӦΪi-1 j-1������ ����dp[i][j]=dp[i-1][j-1]+1����dp[i-1][j] dp[i][j-1]��ֻ��i i-1����״̬ ����0,1����
            int y = 1-x;//��ǰ״̬��x ��i-1״̬��y��ʾ dp[i-1][j-1]=dp[y][j-1] dp[i][j-1]=dp[x][j-1] dp[i-1][j]=dp[y][j]
            if(s1[i-1]==s2[j-1])
				dp[x][j] = dp[y][j-1]+1;
            else
				dp[x][j] = max(dp[y][j],dp[x][j-1]);
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s1);
        for(i = 0;i<n;i++)
			s2[i] = s1[n-1-i];
        s2[i] = '\0';
        LCS();
        printf("%d\n",n-dp[n%2][n]);
    }

    return 0;
}


