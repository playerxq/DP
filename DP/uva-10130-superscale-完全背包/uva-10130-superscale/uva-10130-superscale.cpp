// uva-10130-superscale.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int d[30005];
int p[1005];
int w[1005];
bool vis[30005]; 
int _max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));  
        memset(d,0,sizeof(d));
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
			sum+=w[i];
		}
		vis[0] = 1;
		for(int i = 0;i<n;i++)//前i个物品j重量内的最大价值
		{
			for(int j = sum;j>=w[i];j--)
			{
				if(vis[j-w[i]])
				{
					vis[j] = 1;
					d[j] = _max(d[j],d[j-w[i]]+p[i]);
				}
			}
		}
		scanf("%d",&m); 
		int ans = 0;
        while(m--)  
        {  
            int temp,imax=0;  
            scanf("%d",&temp);  
            for(int i=0;i<=temp;i++) //最接近当前人的重量的最大价值 
            {  
                imax=_max(imax,d[i]);  
            }  
            ans+=imax;  
        }  
        printf("%d\n",ans); 
	}
	return 0;
}

