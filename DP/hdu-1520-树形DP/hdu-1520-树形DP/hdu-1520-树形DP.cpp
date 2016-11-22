// hdu-1520-����DP.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[i][1]��ʾ��i�������߲μ��ˣ�dp[i][0]��ʾ��i��������û�вμӡ�
//״̬ת�Ʒ��̾���dp[i][1]=dp[i][1]+dp[i-1][0]��dp[i][0]=dp[i][0]+Max(dp[i-1][0],dp[i-1][1])

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

#define N 6005  
struct node 
{ 
    int pa,son; 
    int next; //�ֵ�
}point[N];
int dp[N][2],list[N],flag[N],value[N]; 
int pos; 
int Max(int x,int y) 
{ 
    return x>y?x:y; 
} 
void add(int pa,int son) //posλ�ýڵ�ĸ��ڵ���pa �ֵܽڵ���list��
{ 
    point[pos].pa=pa; 
    point[pos].son=son; 
    point[pos].next=list[pa];//��Ϊpa�ӽڵ㡣  nextָ�򱾲��ֵ�
    list[pa]=pos++; 
    return ; 
} 
void dfs(int root) 
{ 
    if(list[root]==-1) 
    { 
        dp[root][1]=value[root]; 
        dp[root][0]=0; 
        return ; 
    } 
    int now=list[root]; //��ǰroot��һ���ӽڵ�
	//����root��ÿ���ӽڵ�
    dp[root][0]=0; 
    dp[root][1]=value[root]; 
    while(now!=-1) 
    { 
        dfs(point[now].son); //̽���ӽڵ�
        dp[root][1]+=dp[point[now].son][0];//
        dp[root][0]+=Max(dp[point[now].son][1],dp[point[now].son][0]);//
        now=point[now].next;//  now ���ֵ�
    } 
    return ; 
} 
 
int main() 
{ 
    int i,n; 
    while(scanf("%d",&n)!=EOF) 
    { 
        for(i=1;i<=n;i++) 
            scanf("%d",&value[i]);//��¼ÿһ�����ֵ  
        int a,b; 
        pos=0; 
        memset(list,-1,sizeof(list)); 
        memset(flag,0,sizeof(flag)); 
        while(scanf("%d%d",&a,&b),a+b) 
        { 
            add(b,a);//���߼�������  
            flag[a]=1;//��¼a�и��ڵ㣬����������ڵ㡣  
        } 
        a=1; 
        while(flag[a]==1) 
            a++;//�ҵ���  
        dfs(a); 
        printf("%d\n",Max(dp[a][0],dp[a][1])); 
    } 
    return 0; 
} 
