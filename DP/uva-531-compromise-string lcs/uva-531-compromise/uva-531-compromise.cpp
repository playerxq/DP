#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char w1[100][31], w2[100][31];
int dp[101][101], path[101][101];
void Print(int sum, int i, int j)//递归打印路径
{
    if(!sum)
        return ;
    if(path[i][j] == 0)
    {
        Print(sum-1, i-1, j-1);
        if(sum != 1)
            printf(" %s", w1[i-1]);
        else
            printf("%s", w1[i-1]);//最后一个数字后没有空格
    }
    else if(path[i][j] == 1) 
        Print(sum, i-1, j);
    else if(path[i][j] == 2)
        Print(sum, i, j-1);
}
int main()
{
freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int cct1, cct2;
    while(scanf("%s", w1[cct1=0]) != EOF)
    {
        while(w1[cct1][0] != '#')
            scanf("%s", w1[++cct1]);
        scanf("%s", w2[cct2=0]);
        while(w2[cct2][0] != '#')
            scanf("%s", w2[++cct2]);

        for(int i=0; i<100; ++i)
            dp[0][i] = dp[i][0] = 0;
        for(int i=1; i<=cct1; ++i)
            for(int j=1; j<=cct2; ++j)
            {
                if(!strcmp(w1[i-1], w2[j-1]))
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    path[i][j] = 0;
                }
                else
                {
                    if(dp[i][j-1] < dp[i-1][j])
                    {
                        dp[i][j] = dp[i-1][j];
                        path[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                        path[i][j] = 2;
                    }
                }
            }
        Print(dp[cct1][cct2], cct1, cct2);
        puts("");
    }
    return 0;
}