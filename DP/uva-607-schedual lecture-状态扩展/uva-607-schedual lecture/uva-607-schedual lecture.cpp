// uva-607-schedual lecture.cpp : 定义控制台应用程序的入口点。
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
#define INF 1<<30
int n,l,c;
int t[1001];
int d[1001][1001];
int vis[1001][1001];
int get(int x) {  //课余时间
    if (x == 0) return 0;  
    else if (x <= 10) return -c;  
    else return (x - 10) * (x - 10);  
} 
int dp(int i, int j)//d[i][j]利用i天安排0:j门课
{
	if(vis[i][j])
		return d[i][j];
	else if(i==0)//没有剩余天数
	{
		if(j>=0)//依然有剩余课程
		{
			d[0][j] = INF;
			return INF;
		}
		else
		{
			return 0;
		}
	}
	d[i][j] = INF;
	int sum = 0;
	for(int k = j;k>=0;k--)//枚举第i天安排的课程数
	{
		sum+=t[k];//第i天课时
		if(sum>l)
			break;
		int opt = dp(i-1,k-1);
		if(opt!=INF)
			d[i][j] = min(opt+get(l-sum),d[i][j]);
	}
	vis[i][j] = 1;
	return d[i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		if(ncase>1)
			printf("\n");
		scanf("%d%d",&l,&c);
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		memset(d,INF,sizeof(d));
		int cnt = 0;
		int sum = 0;
		for(int i = 0;i<n;i++)//课程天数按贪心  尽可能的排满一天
		{
			scanf("%d",&t[i]);
			sum+=t[i];
			if(sum>l)
			{
				sum = t[i];
				cnt++;
			}
		}
		cnt++;//last lecture
		printf("Case %d:\n", ncase++);  
        printf("Minimum number of lectures: %d\n", cnt);
		printf("Total dissatisfaction index: %d\n", dp(cnt, n-1));
	}
	return 0;
}

