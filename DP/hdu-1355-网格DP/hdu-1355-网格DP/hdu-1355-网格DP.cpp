// hdu-1355-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
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
struct Node
{
	int x,y,num;
} map[2555];
int cmp(const void* _a, const void* _b)
{
	struct Node* a = (struct Node*)_a;
	struct Node* b = (struct Node*)_b;
	return b->num-a->num;//����
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t,i,j,m,n,k,a,q,sum,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&m,&n,&k);
		q=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a);
				if(a>0)
				{
					map[q].x=i;
					map[q].y=j;
					map[q].num=a;
					q++;
				}
			}
		qsort(map,q,sizeof(map[0]),cmp);
		sum=0;a=0;b=map[0].y;i=0;
		while(k>0){//ʱ����ʣ��
			if(i==q)break;//û�и�����
			if(abs(map[i].x-a)+abs(map[i].y-b)+map[i].x+1>k)//�߹�ȥ��ʱ����Ϸ��ص�road��ʱ�䲻��
				break;
			else{
				sum+=map[i].num;
				k-=abs(map[i].x-a)+abs(map[i].y-b)+1;//��(a,b)�ߵ�(x,y)����ʱ��
				a=map[i].x;b=map[i].y;
				i++;
			}
		}
		printf("%d\n",sum);
	}
}

