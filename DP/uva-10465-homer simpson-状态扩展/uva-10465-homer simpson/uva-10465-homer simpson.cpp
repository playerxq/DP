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
#define N 10005  
#define INF 0x7fffffff  
int m, n, t, d[N], b[N];  
int main ()  
{  
    while(~scanf("%d%d%d",&m,&n,&t))  
    {  
        for(int i = 0; i <= m; i++) d[i] = 0;  
        for(int i = 0; i <= m; i++) b[i] = i;  
  
        for(int j = m; j <= t; j++)  
        {  
            d[j] = d[j-m]+1;  
            b[j] = b[j-m];  
        }  
        for(int j = n; j <= t; j++)  
        {  
            if(b[j]>b[j-n])  //优先剩余时间
            {  
                d[j] = d[j-n]+1;  
                b[j] = b[j-n];  
            }  
            else if(b[j]==b[j-n])  
            {  
                d[j] = (d[j]>d[j-n]+1?d[j]:d[j-n]+1);  
            }  
        }  
  
        if(b[t])  
        printf("%d %d\n",d[t],b[t]);  
        else  
        printf("%d\n",d[t]);  
    }  
    return 0;  
} 