#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define MAXD 20
#define INF 1000000000
int N, left[MAXD], right[MAXD], f[MAXD][MAXD], p[MAXD][MAXD];
typedef struct Matric
{
	int r;
	int c;
} Mo;
Mo marr[MAXD];
int init()
{
    int i;
    scanf("%d", &N);
    if(!N)
        return 0;
    for(i = 0; i < N; i ++)
		scanf("%d%d", &marr[i].r, &marr[i].c);
}
void printpath(int a, int b)
{
    if(a == b)
    {
        printf("A%d", a + 1);
        return ;
    }
    printf("(");
    printpath(a, p[a][b]);
    printf(" x ");
    printpath(p[a][b] + 1, b);
    printf(")");
}
void solve()
{
    int i, j, k, temp;
    for(i = 0; i < N; i ++)
        for(j = i; j < N; j ++)
        {
            if(i == j)
                f[i][j] = 0;
            else
                f[i][j] = INF;
        }
    for(k = 1; k < N; k ++)
        for(i = 0; i + k < N; i ++)
            for(j = i; j < i + k; j ++)
            {
                temp = f[i][j] + f[j + 1][i + k] + marr[i].r * marr[j].c * marr[i + k].c;
                if(temp < f[i][i + k])
                {
                    f[i][i + k] = temp;
                    p[i][i + k] = j;
                }
            }
    printpath(0, N - 1);
    printf("\n");
}
int main()
{
    int t = 0;
    while(init())
    {
        printf("Case %d: ", ++ t);
        solve();
    }
    return 0;
}