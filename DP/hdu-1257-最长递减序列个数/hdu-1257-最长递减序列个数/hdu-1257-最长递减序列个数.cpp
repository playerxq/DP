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
int n,a[100000],b[100000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int count = 0;
		b[0]=0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
			for(int j = 0;j<=count;j++)
			{
				if(a[i]<b[j])
				{
					b[j]=a[i];
					break;
				}
				else if(j==count)
				{
					count++;
					b[count]=a[i];
					break;
				}
			}
		}
		printf("%d\n",count);
	}
}