// uva-10154-weights and measures.cpp : 定义控制台应用程序的入口点。
//有几只乌龟，每只乌龟有一定的重量与力量。
//每只乌龟可以背小于它力量的重量（包括它自身的重量）。问最多一共可以有多少只乌龟叠在一起。
//显然：
//如果一个力量小的乌龟可以驮着一个力量大的乌龟，那么这个力量大的乌龟也必然可以驮起这个力量小的乌龟，
//而且还能够使两个乌龟上方增加承重能力。

//先把乌龟按力量排序，剩下的问题就是求这个最长非降子序列了。
//对于当前的乌龟i，如果f[j]+w[i]<s[i]且f[j]+w[i]<f[j+1]，那么我们就可以更新f[j+1]了，
//同时如果j+1比max要大的话，我们也需要同时更新max了。
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
typedef struct Tur
{
	int wei;
	int cap;
} tur;
#define INF 1000000000
tur a[5700];
int f[5700];//f[j]表示乌龟一共累j个的时候的最轻的重量，那么显然一开始f[0]应该为0，而其余的都应为INF。
int b[5700];
int cmp(const void* _a, const void* _b)
{
	tur* a = (tur*)_a;
	tur* b = (tur*)_b;
	return a->cap-b->cap;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int w,s;
	int cnt = 0;
	while(scanf("%d%d",&w,&s)!=EOF)
	{
		a[cnt].wei = w;
		a[cnt++].cap = s;
	}
	qsort(a,cnt,sizeof(a[0]),cmp);//力量递增排序
	for(int i = 0;i<cnt;i++)
		f[i] = INF;
	f[0] = 0;
	int maxn = 0;
	for(int i = 0;i<cnt;i++)
	{
		for(int j = maxn;j>=0;j--)
		{
			if(f[j]+a[i].wei<a[i].cap&&f[j]+a[i].wei<f[j+1])//将第i个乌龟放到某个长度为j的串下 看是否能扩展成j+1的串
			{
				f[j+1] = f[j]+a[i].wei;
				if(j+1>maxn)
					maxn = j+1;
			}
		}
	}
	printf("%d\n",maxn);
	return 0;
}

