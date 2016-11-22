// hdu-1574-简单DP.cpp : 定义控制台应用程序的入口点。
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
const int size = 20001;  
int dp[size];  
int T;  
int N;  
bool visited[size];  
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d", &N);  
        int a, b, c;  
        int i;  
        int j;  
        memset(dp, 0, sizeof(dp));  
        memset(visited, 0, sizeof(visited));  
        dp[10000] = 0;  //RP可能为负  补偿10000
        visited[10000] = true; 
		for (i = 0; i < N; i++)  
        {  
            scanf("%d%d%d", &a, &b, &c);  
            if (a > 0)//RP增加  
            {  
                for (j = b + 10000; j >= 0; j--)  //只有RP小于等于门限b时才会发生 
                {  
                    if (visited[j])  //有j的RP
                    {  
                        if (!visited[j + a])  //还没有j+a的RP
                        {  
                            dp[j + a] = dp[j] + c;  
                            visited[j + a] = true;  
                        }  
                        else   //更新一下
                        {  
                            dp[j + a] = max(dp[j + a], dp[j] + c);  
                        }  
                    }  
                }  
            }  
            else if (a < 0)  
            {  
                for (j = b + 10000; j < size; j++)  //RP大于等于门限时才会发生
                {  
                    if (visited[j])  
                    {  
                        if (!visited[j + a])  
                        {  
                            dp[j + a] = dp[j] + c;  
                            visited[j + a] = true;  
                        }  
                        else   
                        {  
                            dp[j + a] = max(dp[j + a], dp[j] + c);  
                        }  
                    }  
                }  
            }  
        }  
        int ans = 0;  
        for (i = 0; i < size; i++)  
        {  
            if (visited[i] && dp[i] > ans)  
            {  
                ans = dp[i];  
            }  
        }  
        printf("%d\n", ans);  
	}

}

