// uva-10029-edit step ladder.cpp : �������̨Ӧ�ó������ڵ㡣
//�����ֵ���ĵ������У���һ�����ʿ��Ծ���insert del replace��Ϊ��һ������Ϊһ�����ݣ����������
//��ÿ�����ʣ�ö�������б仯��ʽ������ǰ���Ƿ��б仯��ĵ��ʣ���������и�ֵ
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
char str[26000][20];
int f[26000];
int cnt;
int binary_s(int be, int end,char* s)
{
	while(be<=end)
	{
		int mid = be+(end-be)/2;
		if(strcmp(str[mid],s)==0)
			return mid;
		if(strcmp(str[mid],s)>0)
			end = mid-1;
		else
			be = mid+1;
	}
	return -1;
}
void dele(char *str,char *res,int pos)  
{  
    int len=strlen(str),cnt=0;  
    for(int i=0;i<len;i++)  
    {  
        if(i!=pos) res[cnt++]=str[i];  
    }  
    res[cnt]='\0';  
}  
void repla(char *str,char *res,int pos,char letter)  
{  
    int len=strlen(str);  
    for(int i=0;i<len;i++)  
    {  
        if(i==pos) res[i]=letter;  
        else res[i]=str[i];  
    }  
    res[len]='\0';  
}  
void add(char *str,char *res,int pos,char letter)  
{  
    int len=strlen(str),cnt=0;  
    for(int i=0;i<=len;i++)  
    {  
        if(i==pos) res[cnt++]=letter;  
        if(i<len) res[cnt++]=str[i];  
    }  
    res[cnt]='\0';  
}
void fun(char *a,int pos)  
{  
    int pre=binary_s(0,pos-1,a);  
    if(pre!=-1) f[pos]=max(f[pos],f[pre]+1);  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%s",str[cnt++])!=EOF)
	{}
	int maxn = 0;
	for(int i = 1;i<cnt;i++)//��ÿ������
	{
		int len = strlen(str[i]);
		for(int j = 0;j<len;j++)//ÿ����ĸ
		{
			char temp[20] = {0};
			for(char k = 'a';k<='z';k++)//��ÿ����ĸ�滻Ϊĳ����ĸ
			{
				if(j<len)
				{
					repla(str[i],temp,j,k); //��ÿ����ĸ�滻Ϊĳ����ĸ 
                    fun(temp,i);
				}
				add(str[i],temp,j,k);  //������ĸ
                fun(temp,i);  
            }  
            if(j<len)  
            {  
                dele(str[i],temp,j);  
                fun(temp,i);  
            }
		}
		maxn = max(maxn,f[i]);
	}
	printf("%d\n",maxn+1);
	return 0;
}

