// hdu-1160-最长升序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"


struct A
{
	int num;
	int pre;
	int dp;
	int w,s;
}E[1011];


int cmp(const void* _a,const void* _b)
{
	struct A* a = (struct A*) _a;
	struct A* b = (struct A*) _b;
	if(a->w!=b->w)	return a->w-b->w;
	else			return b->w-a->w;
}


void print(int d)
{
	if(E[d].pre==d)	{printf("%d\n",E[d].num);return ;}
	print(E[d].pre);
	printf("%d\n",E[d].num);
}


int main()
{
	int k=0;
	int i,l;
	int ans,key;


	while(scanf("%d%d",&E[k].w,&E[k].s)!=-1)	k++;
	for(i=0;i<k;i++)	E[i].num=i+1;
	qsort(E,k,sizeof(E[0]),cmp);


	for(i=0;i<k;i++)	{E[i].pre=i;E[i].dp=0;}
	E[0].dp=1;
	for(i=1;i<k;i++)
	{
		for(l=0;l<i;l++)
		{
			if(E[l].w<E[i].w&&E[l].s>E[i].s)
			{
				if(E[l].dp>E[i].dp)
				{
					E[i].dp=E[l].dp;
					E[i].pre=l;
				}
			}
		}
		E[i].dp++;
	}


	ans=0;
	key=-1;
	for(i=0;i<k;i++)	if(E[i].dp>ans)	{ans=E[i].dp;key=i;}


	printf("%d\n",ans);
	print(key);


	return 0;
}

