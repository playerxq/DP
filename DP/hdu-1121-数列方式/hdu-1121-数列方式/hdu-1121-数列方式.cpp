// hdu-1121-数列方式.cpp : 定义控制台应用程序的入口点。
//逐次相减到最后剩余一个数  此数为原始数据最外面的数逐次相减的结果
//复制c个相同的数  则c个数为所求的c个数逐次相减的结果
//逆推求出所求的c个数即可 由于最外侧的那个原始数据已经在每轮中保存了，因此每次只需考虑新的c个数
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
    for(int i=1;i<n;i++)//逐次向前做差
    {
        for(int j=0;j<n-i;j++)//i行有n-i个元素  注意第0行为原始数据 从第1行开始
        {
            arr[j][i]=arr[j+1][i-1]-arr[j][i-1];//i行j列元素等于i-1行j+1列减去i-1行j列
        }
    }
	//此时剩余第n-1行0列元素
	//在n-1行1:c列上添加相同元素
    for(int i=1;i<=c;i++) arr[i][n-1]=arr[0][n-1];
    for (int i = n-2 ; i >= 0 ; i--)//从下向上
    {
        for (int j = 0 ; j < c ; j++)//第i行 原始数据的最外侧数据在i行的索引是n-1-i 因此新的c个数索引为n-i:n-i+c-1
        {
            arr[n-i+j][i] = arr[n-i+j-1][i+1]+arr[n-i+j-1][i];//递推
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



