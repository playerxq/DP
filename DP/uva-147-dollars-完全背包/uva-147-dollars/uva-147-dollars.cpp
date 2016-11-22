// uva-147-dollars.cpp : 定义控制台应用程序的入口点。
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
int a,b;
long long d[30005];
const int coin[12]={0,5,10,20,50,100,200,500,1000,2000,5000,10000}; 
void dp(int num)
{
	memset(d,0,sizeof(d));
	d[0] = 1;
	for(int i = 1;i<=11;i++)//使用0：i种硬币
	{
		for(int j = 1;j<=num;j++)
		{
			if(j>=coin[i])
				d[j] += d[j-coin[i]]; 
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	while(scanf("%d.%d",&a,&b))
	{
		if(a==0&&b==0)
			break;
		int num = a*100+b;
		dp(num);
		if(b >= 10)  
            printf("%3d.%d", a, b);  
        else  
            printf("%3d.0%d", a, b);  
        printf("%17lld\n", d[num]); 
	}
	return 0;
}

