// hdu-1206-������.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n,m,ind;
int note_time[2830*3+10][8];//��ͬnoteʱ�̶�Ӧ��״̬
int dp[256][256];//dp[i][j]��ǰʱ��note״̬Ϊi ֮��ʱ��note״̬Ϊj�ķ���
int dp_temp[256][256];
int end_t;//���ʱ��
int note_ex[2830*3+10][8];//ԭʼnote
int note_temp[2830][8];//����
struct Note
{
	int t,p;
} in_note[2830];//�����note
int note_ind;//��չ��note��Ŀ
int in_note_ind;
int key_board[256][8];//���п��еļ���״̬
int vis[256];
bool ok(int sta)
{
	int temp[8]={0};
	for(int i = 1;i<=7;i++)
		if(sta&(1<<(7-i)))
			temp[i]=1;
	int cnt1,cnt2;
	cnt1=cnt2=0;
	for(int i = 1;i<=7;i++)
	{
		if(i<=4&&temp[i]==1)
			cnt1++;
		if(i>4&&temp[i]==1)
			cnt2++;
	}
	return ((cnt1<=3)&&(cnt2<=2));
}
void init()
{
	memset(vis,0,sizeof(vis));
	memset(key_board,0,sizeof(key_board));
	for(int i = 0;i<256;i++)
	{
		if(ok(i))
		{
			vis[i]=1;
			for(int k = 1;k<=7;k++)
			{
				if(i&(1<<(7-k)))
					key_board[i][k]=1;
			}
		}
	}
}
void copy_note(int src, int des)
{
	for(int i = 0;i<=7;i++)
		note_ex[des][i]=note_temp[src][i];
}
void expend()//������in_note��չΪnote[]
{
	memset(note_temp,0,sizeof(note_temp));
	memset(note_ex,0,sizeof(note_ex));
	int pre_t = 0;
	int inde = 0;
	for(int i = 0;i<in_note_ind;i++)//��ÿ��note
	{
		if(in_note[i].t==pre_t)
		{
			note_temp[inde][in_note[i].p]=1;
		}
		else if(pre_t==0)
		{
			pre_t = in_note[i].t;
			note_temp[inde][0]=pre_t;
			note_temp[inde][in_note[i].p]=1;
		}
		else
		{
			pre_t = in_note[i].t;
			inde++;
			note_temp[inde][0]=pre_t;
			note_temp[inde][in_note[i].p]=1;
		}
	}
	//��չnote_temp
	note_ind = 0;
	if(note_temp[0][0]>0)//��һ��note��ʼʱ�����0 ������չ��һ��note_temp[0][0]-1��ʱ��
	{
		note_ex[0][0]=note_temp[0][0]-1;
		note_ind++;//��ʼʱ��note��Ϊ0
	}
	for(int i = 0;i<inde+1;i++)
	{
		if(note_ind==0)//��һ��ʱ���޷�������չ  
		{
			copy_note(0,0);
			note_ind++;
			note_ex[note_ind][0]=note_temp[i][0]+1;//������չ
			note_ind++;
			continue;
		}
		if(note_temp[i][0]-1>note_ex[note_ind-1][0])//������չһ��ʱ��
		{
			note_ex[note_ind][0]=note_temp[i][0]-1;//����������0
			note_ind++;
		}
		if(note_temp[i][0]>=note_ex[note_ind-1][0])//��ӵ�ǰʱ�� ���ʱ˵����һ��ʱ�����ϴ�������չ�õ���  Ӧ����
		{
			if(note_temp[i][0]==note_ex[note_ind-1][0])
			{
				copy_note(i,note_ind-1);
			}
			else
			{
				copy_note(i,note_ind);
				note_ind++;
			}
		}
		if(note_temp[i][0]+1>note_ex[note_ind-1][0])//����������չһ��ʱ��
		{
			note_ex[note_ind][0]=note_temp[i][0]+1;
			note_ind++;
		}
	}
	for(int i = 0;i<note_ind;i++)
	{
		note_ex[i][0]=0;
		for(int j = 1;j<=7;j++)
			if(note_ex[i][j])
				note_ex[i][0]+=(1<<(7-j));
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		end_t = 0;
		memset(dp,0,sizeof(dp));
		memset(dp_temp,0,sizeof(dp_temp));
		memset(in_note,0,sizeof(in_note));
		in_note_ind = 0;
		for(int i = 1;i<=m;i++)
		{
			int t,p;
			scanf("%d%d",&t,&p);
			in_note[in_note_ind].p =p;
			in_note[in_note_ind++].t = t;
			if(t>end_t)
				end_t = t;
		}
		expend();
		//��ʼʱ��note_ex[0][0]>=0һ���ǵ�һ����ʵʱ�̵�ǰһ��ʱ�̣�������0����û��һ��note
		for(int i = 0;i<256;i++)
		{
			if(vis[i])//���м���״̬
			{
				int score = 0;
				int now = 0;//��ǰʱ��note״̬
				int next = note_ex[1][0];//�¸�ʱ��note״̬
				//���Խ���һ��ʱ�̵�ĳЩnote�õ�
				for(int k = 1;k<=7;k++)
				{
					if(key_board[i][k]==1&&note_ex[1][k])//��ʼʱ��kλ����  ����һ��ʱ����note
					{
						score+=5;
						next-=(1<<(7-k));
						now+=(1<<(7-k));
					}
				}
				//����ʣ���nextΪ����ʼ����״̬iʱ����һʱ�̵�note״̬
				dp[now][next]=max(dp[now][next],score);
			}
		}
		//�Ժ���ʱ��  ����dp
		if(end_t==n)//���ʱ��Ϊn �޷�ʹ��������չ���Ǹ�ʱ��
			note_ind--;
		for(int t = 1;t<note_ind;t++)//��tʱ��
		{
			int next_o = note_ex[t+1][0];//����t+1ʱ��ԭʼ��note״̬
			//��Ѱ֮ǰt-1ʱ�̼����dp ����״̬ ��֮ǰ��next����Ϊ���ڵ�now ֮ǰ��now��Ϊ���ڵ�pre
			for(int pre_i = 0;pre_i<256;pre_i++)
			{
				for(int now_i = 0;now_i<256;now_i++)
				{
					if(dp[pre_i][now_i]!=0)//�ɴ��
					{
						int score = dp[pre_i][now_i];
						int pre = pre_i;
						int now = now_i;
						int next = next_o;//��ʼ��next״̬
						//��pre now next �Ƴ��µ�now�Լ�next�µ����ֵ
						
					}
				}
			}//�Ե�ǰʱ��i��λ״̬�������
			//�����µ�dp
			memcpy(dp,dp_temp,sizeof(dp));
			memset(dp_temp,0,sizeof(dp_temp));
		}
		int maxx = 0;
		for(int i = 0;i<256;i++)
		{
			for(int j = 0;j<256;j++)
			{
				if(dp[i][j]>maxx)
					maxx = dp[i][j];
			}
		}
		printf("%d\n",maxx);
	}
}

