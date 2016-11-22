// uva-10306-e-coins.cpp : 定义控制台应用程序的入口点。
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
#include <climits>
using namespace std;
int m,s;
int d[310][310];//第一个值i 第二个值j的需要的硬币数目
int w1[50];
int w2[50];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&s);
		memset(d,0,sizeof(d));
		for(int i = 0;i<m;i++)
		{
			scanf("%d%d",&w1[i],&w2[i]);
		}
		for(int i = 0;i<=s;i++)
			for(int j = 0;j<=s;j++)
				d[i][j] = INT_MAX;
		d[0][0] = 0;
		for(int i = 0;i<m;i++)//考虑第i种硬币
		{
			for(int j = w1[i];j<=s;j++)
			{
				for(int k = w2[i];k<=s;k++)
				{
					if(d[j-w1[i]][k-w2[i]]!=INT_MAX)
						d[j][k] = min(d[j][k],d[j-w1[i]][k-w2[i]]+1);
				}
			}
		}
		int ans = INT_MAX;
        int t = s * s;
        for (int i = 0; i <= s; ++i)
            for (int j = 0; j <= s; ++j)
                if (i * i + j * j == t && d[i][j] != INT_MAX)
                    if (ans > d[i][j])
                        ans = d[i][j];

        if (ans != INT_MAX)
            printf("%d\n", ans);
        else
            printf("not possible\n");
	}
	return 0;
}

