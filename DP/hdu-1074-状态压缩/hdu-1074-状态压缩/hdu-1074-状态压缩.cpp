// hdu-1074-״̬ѹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
״̬ѹ��dp
���ڵ���״̬i,ö�����е���ҵ
���������ҵk,i�к�����ҵk����ɣ���ôi�����ɺ�i״̬��ͬ��״̬������kδ��ɵ�
״̬j=i-(1<<k)�����k����,����jһ����iС�����״̬��0ö�ٵ�2^n-1��ôjһ������i֮ǰ�Ѿ�������� 
*/
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<15)+10;
int n;
int dp[MAX],t[MAX],pre[MAX],dea[20],fin[20];//dp[i]��¼����״̬i�۵����ٷ�,tʱ��Ӧ�Ļ�ȥ��������
char s[20][110];

void output(int x){
	if(!x)return;
	output(x-(1<<pre[x]));
	printf("%s\n",s[pre[x]]);
}

int main(){
	    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%s%d%d",&s[i],&dea[i],&fin[i]);
		int bit=1<<n;
		for(int i=1;i<bit;++i){//ö�ٵ���״̬i
			dp[i]=INF;
			for(int j=n-1;j>=0;j--){//�ȵõ�������С��״̬
				int temp=1<<j;
				if(!(i&temp))continue;//״̬i������j
				int score=t[i-temp]+fin[j]-dea[j];
				if(score<0)score=0; 
				if(dp[i]>dp[i-temp]+score){
					dp[i]=dp[i-temp]+score;
					t[i]=t[i-temp]+fin[j];//����״̬i���ѵ�ʱ��
					pre[i]=j;//����״̬i��ǰ��
				} 
			}
		}
		printf("%d\n",dp[bit-1]);
		output(bit-1);//��������ҵ��˳�� 
	}
	return 0;
} 

