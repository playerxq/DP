// hdu-1206-劲舞团.cpp : 定义控制台应用程序的入口点。
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
int note_time[2830*3+10][8];//不同note时刻对应的状态
int dp[256][256];//dp[i][j]当前时刻note状态为i 之后时刻note状态为j的分数
int dp_temp[256][256];
int end_t;//最后时刻
int note_ex[2830*3+10][8];//原始note
int note_temp[2830][8];//辅助
struct Note
{
	int t,p;
} in_note[2830];//输入的note
int note_ind;//扩展后note数目
int in_note_ind;
int key_board[256][8];//所有可行的键盘状态
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
void expend()//将输入in_note扩展为note[]
{
	memset(note_temp,0,sizeof(note_temp));
	memset(note_ex,0,sizeof(note_ex));
	int pre_t = 0;
	int inde = 0;
	for(int i = 0;i<in_note_ind;i++)//对每个note
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
	//扩展note_temp
	note_ind = 0;
	if(note_temp[0][0]>0)//第一个note起始时间大于0 可以扩展出一个note_temp[0][0]-1的时刻
	{
		note_ex[0][0]=note_temp[0][0]-1;
		note_ind++;//起始时刻note均为0
	}
	for(int i = 0;i<inde+1;i++)
	{
		if(note_ind==0)//第一个时刻无法向下扩展  
		{
			copy_note(0,0);
			note_ind++;
			note_ex[note_ind][0]=note_temp[i][0]+1;//向上扩展
			note_ind++;
			continue;
		}
		if(note_temp[i][0]-1>note_ex[note_ind-1][0])//向下扩展一个时刻
		{
			note_ex[note_ind][0]=note_temp[i][0]-1;//此行其余是0
			note_ind++;
		}
		if(note_temp[i][0]>=note_ex[note_ind-1][0])//添加当前时刻 相等时说明上一个时刻是上次向上扩展得到的  应覆盖
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
		if(note_temp[i][0]+1>note_ex[note_ind-1][0])//尝试向上扩展一个时刻
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
		//起始时刻note_ex[0][0]>=0一定是第一个真实时刻的前一个时刻（至少是0）且没有一个note
		for(int i = 0;i<256;i++)
		{
			if(vis[i])//可行键盘状态
			{
				int score = 0;
				int now = 0;//当前时刻note状态
				int next = note_ex[1][0];//下个时刻note状态
				//尝试将下一个时刻的某些note用掉
				for(int k = 1;k<=7;k++)
				{
					if(key_board[i][k]==1&&note_ex[1][k])//起始时刻k位按下  且下一个时刻有note
					{
						score+=5;
						next-=(1<<(7-k));
						now+=(1<<(7-k));
					}
				}
				//现在剩余的next为在起始键盘状态i时的下一时刻的note状态
				dp[now][next]=max(dp[now][next],score);
			}
		}
		//对后续时刻  计算dp
		if(end_t==n)//最后时刻为n 无法使用向上扩展的那个时刻
			note_ind--;
		for(int t = 1;t<note_ind;t++)//对t时刻
		{
			int next_o = note_ex[t+1][0];//计算t+1时刻原始的note状态
			//搜寻之前t-1时刻计算的dp 键盘状态 且之前的next将作为现在的now 之前的now作为现在的pre
			for(int pre_i = 0;pre_i<256;pre_i++)
			{
				for(int now_i = 0;now_i<256;now_i++)
				{
					if(dp[pre_i][now_i]!=0)//可达的
					{
						int score = dp[pre_i][now_i];
						int pre = pre_i;
						int now = now_i;
						int next = next_o;//初始的next状态
						//由pre now next 推出新的now以及next下的最大值
						
					}
				}
			}//对当前时刻i键位状态遍历完成
			//保存新的dp
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

