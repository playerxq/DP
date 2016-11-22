// hdu-1421-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[i][j]��ʾǰi����Ʒ��ѡj�Ե���Сƣ�Ͷ�
//dp[i][j]=min{dp[i-2][j-1]+(val[i]-val[i-1])*(val[i]-val[i-1]),dp[i-1][j]  ����i����Ʒһ���͵�i-1����ԣ���������

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
#define size 2005
int cmp(const void *a,const void *b)  
{  
    return *(int *)a-*(int *)b;  
}  
  
int Min(int a,int b)  
{  
    return a<b?a:b;  
}  
#define INIT 2147483646  
int dp[size][1005];  
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,k,i,j;  
    int val[size] = {0};  
    dp[0][0] = 0;  
    while (scanf("%d%d",&n,&k)!=EOF)  
    {  
        val[0] = 0;  
        for(i=1;i<=n;i++)  
            scanf("%d",&val[i]);  
        qsort(val+1,n,sizeof(val[0]),cmp);  
        for (i=0;i<=n;i++)  
        {  
            for(j=1;j<=k;j++)  
                dp[i][j] = INIT;  
        }  
        for (i=2;i<=n;i++)  
        {  
            for (j=1;j*2<=i;j++)  
                dp[i][j] = Min(dp[i-2][j-1]+(val[i]-val[i-1])*(val[i]-val[i-1]),dp[i-1][j]);  
        }  
        printf("%d\n",dp[n][k]);  
    }  
}

