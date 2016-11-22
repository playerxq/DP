// uva-10817-headmaster headache.cpp : �������̨Ӧ�ó������ڵ㡣
//��n����ʦ��m����ְ�ߡ���֪ÿ�˵Ĺ��ʺ��ܽ��Ŀγ̼��ϣ�
//Ҫ��֧�����ٵĹ���ʹ��ÿ�ſζ�������������ʦ��ѧ����ְ��ʦ������Ƹ
//��16λ2����������ʾ��2�����д�����������ǰ8Ϊ��ʾ��1λ��ʦ�̸��ſγ̣�
//��8Ϊ��ʾ��2λ��ʦ�̣���λ-8���Ŀγ�
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
#define INF 0x3f3f3f3f

#define N (1<<16)+5//��8λ��ʾһ��������i�γ� ��8λ2�������ϵ�i���γ�
int vis[N][105];
int d[N][105];//d[i][j]��j����ʦ�Ƿ��Ӷ���״̬Ϊi
int v[105];
int s,m,n,st,T;
int lesson[105][20];
int dp(int st, int i)
{
	if(vis[st][i])
		return d[st][i];
    vis[st][i]=1;
 
    if(st==T)//����Ŀ��
		return d[st][i]=0;
    if(i==n)
		return INF;
    int next=st,&top=lesson[i][0];
    for(int j=1;j<top;j++)//��Ӷ��i���˶�״̬�����ĸı�
    {
        int y=lesson[i][j];//��j���γ�y
        if((1<<(s+y))&next)//�Ѿ���2���˽�
			continue;
        if((1<<y)&next)
			next=next-(1<<y)+(1<<(s+y));
        else
			next=next+(1<<y);
    }
    if(next!=st)//�й�Ӷ��Ҫ
		d[st][i]=min(d[st][i],dp(next,i+1)+v[i]);
    d[st][i]=min(d[st][i],dp(st,i+1));//����Ӷ
    return d[st][i];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&s,&m,&n),s+m+n)
	{
		st=0;
		int ans = 0;
        char t[100];
        memset(vis,0,sizeof(vis));
        memset(d,INF,sizeof(d));
		for(int i = 0;i<m;i++)//ÿ����ʦ�Ŀγ�״̬
		{
			int x,y;
            scanf("%d",&x);
            ans+=x;
            gets(t);
            int k=strlen(t);
            for(int j=0;j<k;j++)
            {
                sscanf(t+j,"%d",&y);
                y--;//�ѽ̿γ�
                for(;isdigit(t[j]);++j);
                ++j;//skip space
                if(1<<(s+y)&st)//2��
					continue;
                if(1<<y&st)//�Ѿ���һ������
					st=st-(1<<y)+(1<<(s+y));
                else
					st=st+(1<<y);
            }
		}
		for(int i = 0;i<n;i++)//
		{
			scanf("%d",&v[i]);
			int& top = lesson[i][0] = 1;//��i���˵Ŀγ���
            gets(t);
            int k=strlen(t);
            for(int j=0;j<k;j++)
            {
                sscanf(t+j,"%d",&lesson[i][top++]);
                lesson[i][top-1]--;
                for(;isdigit(t[j]);++j);
                ++j;//skip space
            }
		}
		T=0;
        for(int i=s;i<2*s;i++)//Ŀ��  ÿ����2����  ��λ��һ
			T+=(1<<i);
        printf("%d\n",ans+dp(st,0));
	}
	return 0;
}

