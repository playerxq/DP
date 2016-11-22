// uva-10636-prince and princess.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n,p,q;
int a[255*255];
int b[255*255];
int B[255*255];
int k,last;
int binary_s(int be, int end, int x)
{
	while(be<=end)
	{
		int mid = be+(end-be)/2;
		if(B[mid]==x)
			return mid;
		else if(B[mid]<x)
			be = mid+1;
		else
			end = mid-1;
	}
	return be;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 1;
	while(T--)
	{
		scanf("%d%d%d",&n,&p,&q);
		int temp = 0;
		for(int i = 0;i<p+1;i++)
		{
			scanf("%d",&temp);
			a[temp] = i+1;//a[i]��һ�����е��ַ�i���ֵ�λ��
		}
		k = 0;
		for(int i = 0;i<q+1;i++)
		{
			scanf("%d",&temp);
			if(a[temp])//��a�г���  �ǹ�����
			{
				b[k++] = a[temp];//���ڶ������г��ֵ�˳��  ����a[i]��b�� ���b�а�����2�������е��ַ� b������˳���ǵڶ�������˳�� b[i]��ֵ��һ������Ӧ�ַ����ֵ�λ�� 
			}
		}
		//�ҵ�b��������м���
		B[0] = b[0];
		last = 1;
		for(int i = 1;i<k;i++)
		{
			if(b[i]>B[last-1])
			{
				B[last++] = b[i];
			}
			else
			{
				int res = binary_s(0,last-1,b[i]);
				if(B[res]>b[i])
					B[res] = b[i];
			}
		}
		printf("Case %d: %d\n",ncase++,last);//0:last-1
	}
	return 0;
}

