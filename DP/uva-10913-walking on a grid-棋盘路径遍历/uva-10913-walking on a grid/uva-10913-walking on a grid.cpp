// uva-10913-walking on a grid.cpp : �������̨Ӧ�ó������ڵ㡣
//��һ����С��N�����75���ķ���Ҫ��ӣ�1��1���ߵ���n,n��
//��ֻ�������������ҡ��¡������߳�����
//һ������ֻ����һ�Ρ���Ҫ��֤���·���ϵĸ��ӵĺ����
//�����ֻ����k(���Ϊ5)����Ȩֵ�ĸ��ӣ�����㵽�յ�

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
#define LL long long  
#define INF -((LL)1<<60)
int n,k;
long long a[80][80];
long long d[80][80][7][3];
int vis[80][80][7][3];
int flag[80][80];
int dir[3][2]={{0,1},{1,0},{0,-1}}; //�� �� ��
int ok(int i, int j)
{
	if(i>=1&&i<=n&&j>=1&&j<=n)
		return 1;
	return 0;
}
long long dp(int x, int y, int z, int r)//z: ʣ�ฺ������+1  ����������ֵ�� z>=1���ܼ�����
{
	int& fff = vis[x][y][z][r];
	long long& ans = d[x][y][z][r];
	if(fff)
		return ans;
	else if((x==n&&y==n)||(z==0))//�����յ�  ���߸��������Ѿ����� 
	{
		fff = 1;
		if(z==0)
			return ans = INF;//connot reach
		return ans = a[x][y];
	}
	else
	{
		ans = INF;
		for(int i=0;i<3;i++)  
        {  
            int xx=x+dir[i][0],yy=y+dir[i][1],t=0;  
            if(a[x][y]<0) t=-1;  
            if(ok(xx,yy)&&!flag[xx][yy])  //����δ�߹�
            {  
                if((r==0&&i==2)||(r==2&&i==0)) continue;  //����ԭ���򷵻�
                flag[xx][yy]=1;  
                LL temp=dp(xx,yy,z+t,i);  
                if(temp!=INF) ans=max(ans,temp+a[x][y]);  
                flag[xx][yy]=0;  
            }  
        }
		fff = 1;
		return ans;
	}

}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&n,&k))
	{
		if(n+k==0)
			break;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				scanf("%lld",&a[i][j]);
		if(a[n][n]<0) k--;
		memset(d,INF,sizeof(d));
		memset(vis,0,sizeof(vis));
		LL res=dp(1,1,k+1,1);  
        printf("Case %d: ",ncase++);  
        if(res!=INF) printf("%lld\n",res);  
        else printf("impossible\n");
	}
	return 0;
}

