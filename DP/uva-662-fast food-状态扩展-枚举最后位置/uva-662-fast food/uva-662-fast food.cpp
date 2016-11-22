// uva-662-fast food.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3f3f3f3f;
int n,k;
int a[210];
int d[210][35];
int dis[250][250];
int mark[250][250];
int mid[250][250];
int idx;
int get_sum(int i,int j)
{
	int sum = 0;
	int mid = (i+j)/2;
	for(int x = i;x<=j;x++)
	{
		sum+=abs(a[x]-a[mid]);
	}
	return sum;
}
void output(int i, int j)
{
	if (i < 1 || j < 1) return;

    output(mark[i][j] - 1, j - 1);

    printf("Depot %d at restaurant %d serves restaurant", idx++, mid[mark[i][j]][i]);

    if (mark[i][j] == i) {
        printf(" %d\n", i);
    } else {
        printf("s %d to %d\n", mark[i][j], i);

    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&n,&k))
	{
		if(n==0&&k==0)
			break;
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("Chain %d\n",ncase++);
		memset(dis,0,sizeof(dis));
		for(int i = 1;i<=n;i++)
		{
			mid[i][i] = i;
			for(int j = i+1;j<=n;j++)
			{
				mid[i][j] = (i+j)>>1;
				dis[i][j] = get_sum(i,j);
			}
		}
		for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                d[i][j] = INF;
		//memset(d[0], 0, sizeof (d[0]));
		for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
			{
                for (int k = 1; k <= i; ++k) 
				{
                    int tmp = d[k - 1][j - 1] + dis[k][i];
                    if (tmp <= d[i][j])
					{
                        mark[i][j] = k;//1:i中开了j个depot的最后一个控制的最左边的店号
                        d[i][j] = tmp;
                    }
                }
            }
		idx = 1;
		output(n,k);
		printf("Total distance sum = %d\n\n",d[n][k]);
	}
	return 0;
}

