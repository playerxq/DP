// uva-10029-edit step ladder.cpp : 定义控制台应用程序的入口点。
//给定字典序的单词序列，若一个单词可以经过insert del replace变为另一个，则为一个阶梯，问最长阶梯数
//对每个单词，枚举其所有变化形式，查找前面是否有变化后的单词，按最长增序列赋值
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
	for(int i = 1;i<cnt;i++)//对每个单词
	{
		int len = strlen(str[i]);
		for(int j = 0;j<len;j++)//每个字母
		{
			char temp[20] = {0};
			for(char k = 'a';k<='z';k++)//将每个字母替换为某个字母
			{
				if(j<len)
				{
					repla(str[i],temp,j,k); //将每个字母替换为某个字母 
                    fun(temp,i);
				}
				add(str[i],temp,j,k);  //插入字母
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

