// uva-11258-string partition.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ���ַ�������0~9��ɣ����ڿ��Խ��ַ����и�����ɶΣ�ÿһ�α�ɴ���һ����ֵ��
//���������ֵ���ܴ���int��������ޣ��ʣ�����и����ʹ�������ɸ����ĺ����

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
char str[205];
long long d[205];//ǰ0:iλ���Ž�
const int INF = INT_MAX; 
long long max(long long a, long long b) {  
    return a > b ? a : b;  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(str);
		
		int len = strlen(str);
		for(int i = 1; i <= len; i++) d[i] = -INF;  
		d[0] = str[0]-'0';
		for(int i = 1;i<len;i++)
		{
			for(int j = i-1;j+1>=0&&j>=i-10;j--)//��j+1:i���һ���� int���ܳ���10λ
			{
				long long num = 0;
				if(str[j+1]=='0'&&i-j>1)//
					continue;
				for(int k = j+1;k<=i;k++)
					num = num*10+str[k]-'0';
				if(num>=0&&num<=INT_MAX)
				{
					if(j>=0)//����ʣ���ַ�
						d[i] = max(d[i],d[j]+num);
					else
						d[i] = max(d[i],num);
				}
				else 
					break;
			}
		}
		printf("%lld\n",d[len-1]);
	}
	return 0;
}

