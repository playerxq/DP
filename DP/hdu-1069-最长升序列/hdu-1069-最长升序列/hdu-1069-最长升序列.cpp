// hdu-1069-最长升序列.cpp : 定义控制台应用程序的入口点。
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
struct abc
{
	int a,b,c;//长宽高
} cube[1000];
bool cmp(struct abc aa, struct abc bb)
{
	if(aa.a==bb.b) return aa.b>bb.b;
	return aa.a>bb.a;
}
void paixu(int a[])
{
	int i,j,t;
	for(i = 0;i<3;i++)
	{
		for(j = i;j<3;j++)
		{
			if(a[j]>a[i])
			{
				t = a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j;
    int aaa[3];
     int maxsum[1000];
    int count;
     int sum;
     int cas=1;
 
     while(cin>>n&&n)
    {
         memset(maxsum,0,sizeof(maxsum));
         count=0;
         sum=0;
         for(i=0; i<n; ++i)
         {
             cin>>aaa[0]>>aaa[1]>>aaa[2];
             paixu(aaa);//高有3种情况即aaa[0] aaa[1]  aaa[2]保证在每种情况下长》宽
             cube[count].a=aaa[0];
             cube[count].b=aaa[1];
             cube[count].c=aaa[2];
             count++;
             cube[count].a=aaa[1];
             cube[count].b=aaa[2];
             cube[count].c=aaa[0];
             count++;
             cube[count].a=aaa[0];
             cube[count].b=aaa[2];
             cube[count].c=aaa[1];
             count++;
        }
         sort(cube,cube+count,cmp);
         int maxx;
        for(i=0; i<count; ++i)
             maxsum[i]=cube[i].c;
         for(i=0; i<count; ++i)
        {
             maxx=0;
             for(j=0; j<i; ++j)
             {
                 if(cube[j].b>cube[i].b&&cube[j].a>cube[i].a&&maxsum[j]>maxx)
                 {
                     maxx=maxsum[j];
                 }
             }
             maxsum[i]=maxsum[i]+maxx;
         }
         sum=maxsum[0];
         for(i=1; i<count; ++i)
             if(maxsum[i]>sum)
             {
                 sum=maxsum[i];
             }
         cout<<"Case "<<cas++<<": maximum height = "<<sum<<endl;
    }
}

