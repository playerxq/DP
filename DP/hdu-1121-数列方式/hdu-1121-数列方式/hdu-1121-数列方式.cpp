// hdu-1121-���з�ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//�����������ʣ��һ����  ����Ϊԭʼ��������������������Ľ��
//����c����ͬ����  ��c����Ϊ�����c�����������Ľ��
//������������c�������� �����������Ǹ�ԭʼ�����Ѿ���ÿ���б����ˣ����ÿ��ֻ�迼���µ�c����
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

const int N=110;
int n,c,arr[N][N];
void fun()
{
    for(int i=1;i<n;i++)//�����ǰ����
    {
        for(int j=0;j<n-i;j++)//i����n-i��Ԫ��  ע���0��Ϊԭʼ���� �ӵ�1�п�ʼ
        {
            arr[j][i]=arr[j+1][i-1]-arr[j][i-1];//i��j��Ԫ�ص���i-1��j+1�м�ȥi-1��j��
        }
    }
	//��ʱʣ���n-1��0��Ԫ��
	//��n-1��1:c���������ͬԪ��
    for(int i=1;i<=c;i++) arr[i][n-1]=arr[0][n-1];
    for (int i = n-2 ; i >= 0 ; i--)//��������
    {
        for (int j = 0 ; j < c ; j++)//��i�� ԭʼ���ݵ������������i�е�������n-1-i ����µ�c��������Ϊn-i:n-i+c-1
        {
            arr[n-i+j][i] = arr[n-i+j-1][i+1]+arr[n-i+j-1][i];//����
        }
    }
    for (int i = n ; i < n+c-1 ; i++)printf("%d ",arr[i][0]);
    printf("%d\n",arr[n+c-1][0]);
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("testin.txt","r",stdin);
    //freopen("testout.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&c);
        for(int i=0;i<n;i++) scanf("%d",&arr[i][0]);
        fun();
    }
    return 0;
}



