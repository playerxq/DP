// uva-10118-free candies.cpp : 定义控制台应用程序的入口点。
//枚举可能的组合  DFS

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
int n;
const int MAXN = 41;
int a[4][MAXN];
int top[4];
int d[MAXN][MAXN][MAXN][MAXN];
int dp(int count, int basket[])//count  已经在篮子里的颜色数目
{
	if (d[top[0]][top[1]][top[2]][top[3]] != -1)
        return d[top[0]][top[1]][top[2]][top[3]];

    if (count == 5) //不能新加了
        return d[top[0]][top[1]][top[2]][top[3]] = 0;
	int ans = 0;
	for(int i = 0;i<4;i++)//遍历五种颜色
	{
		if(top[i]==n)//全用完了
			continue;
		int c = a[i][top[i]];//取当前颜色的蜡烛
		top[i]++;
		if(basket[c])//篮子里有相同颜色的蜡烛
		{
			basket[c] = 0;
			ans = max(ans,dp(count-1,basket)+1);
			basket[c] = 1;
		}
		else//没有
		{
			basket[c] = 1;
			ans = max(ans, dp(count+1, basket));
			basket[c] = 0;
		}
		top[i]--;
	}
	return d[top[0]][top[1]][top[2]][top[3]] = ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		int hash[25];
		memset(a,0,sizeof(a));
		memset(hash,0,sizeof(hash));
		memset(d, -1, sizeof(d));
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<4;j++)
				scanf("%d",&a[j][i]);
		}
		top[0] = top[1] = top[2] = top[3] = 0;
        printf("%d\n", dp(0, hash));
	}
	return 0;
}

