// uva-10599-robot2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
int a[105][105];
int r,col;
int ncase = 1;
long long d[105][105];//�õ�G��Ŀ
long long c[105][105];//·��
int ans[105*105],top;
long long dp(int i, int j)//������������·���ϵ�������Ŀ
{
	if(d[i][j]!=-1)
		return d[i][j];
	if(i==r&&j==col)
	{
		return d[r][col] = a[r][col];
	}
	d[i][j] = 0;
	if(i+1<=r)
		d[i][j]=max(d[i][j],a[i][j]+dp(i+1,j));
    if(j+1<=col)
		d[i][j]=max(d[i][j],a[i][j]+dp(i,j+1));
	return d[i][j];
}
long long dp_c(int i, int j)//·����  ע��(i,j)��(x,y)·����û�������Ļ�  ������·����һ��
{
	if(c[i][j]!=-1)
		return c[i][j];
	if(d[i][j]==a[i][j])//(i,j)���յ��·����û������������  ��ֻ��һ��·��
		return c[i][j] = 1;
	c[i][j] = 0;
	for(int dx = 0;i+dx<=r;dx++)//��(i,j)Ѱ����һ��������  �Ҵ�������Ӧ���������·����
	{
		for(int dy = 0;dy+j<=col;dy++)
		{
			if(!dx&&!dy)
				continue;
			int x=i+dx,y=j+dy;
			if(a[x][y]&&d[i][j]==d[x][y]+a[i][j])//��һ�������������������·���ϣ��м�ո���·��
				c[i][j]+=dp_c(x,y);
		}
	}
	return c[i][j];
}

void print(int i,int j)//(i,j)��������  ����ӡ����·��
{
    if(a[i][j])
    {
        int dep=d[1][1]-d[i][j];
        ans[dep]=(i-1)*col+j;
    }
    if(d[i][j]==a[i][j])
		return ;
    bool ok=true;
    for(int dx=0;i+dx<=r&&ok;dx++)
		for(int dy=0;j+dy<=col&&ok;dy++)
		{
			if(!dx&&!dy)
				continue;
			int x=i+dx,y=j+dy;
			if(a[x][y]&&d[i][j]==d[x][y]+a[i][j])
			{
				print(x,y);//����һ���������ӡ
				ok=false;
			}
		}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&r,&col),r!=-1||col!=-1)
    {
        memset(a,0,sizeof(a));
        memset(d,-1,sizeof(d));
        memset(c,-1,sizeof(c));
        for(;;)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x+y==0)
				break;
            a[x][y]++;
        }
        top=dp(1,1);
        dp_c(1,1);
        print(1,1);
        printf("CASE#%d: %I64d %I64d",ncase++,d[1][1],c[1][1]);
        for(int i=0;i<top;i++)
			printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}

