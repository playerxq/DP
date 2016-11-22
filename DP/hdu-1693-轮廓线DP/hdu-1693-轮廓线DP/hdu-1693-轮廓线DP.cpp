// hdu-1693-������DP.cpp : �������̨Ӧ�ó������ڵ㡣
//F[i,j,k]��ʾ��������i��j�г���͹��������״̬Ϊk�ķ�������
//�������������ȣ������״̬ӦΪ����+1  ��Ϊ(i,j)λ�õ�����������������ߵĵ�(c-j-1)λ  (i,j)���������Ӧ��c-jλ
*/
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
long long dp[12][12][1<<12];
long r,c;
long map[12][12];
void read(){
     long i,j;
     scanf("%ld%ld",&r,&c);
     for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
           scanf("%ld",&map[i][j]);
}
void solve(){
     long i,j,k,p;
     long x,y;
     memset(dp,0,sizeof(dp));
     dp[0][c][0]=1;
     for(i=0;i<=r;i++){
         for(j=1;j<=c;j++){
             if(i==0&&j<c) continue;
             for(k=0;k<(1<<(c+1));k++) //c+1λ
               if(dp[i][j][k])//��ʼ�ж�j+1�����i+1�е�һ��
			   {
                  if(j==c)//��j�ж���ȫ���״̬����ֵ����һ�еĵ�һ��Ԫ��
				  {            
                     if(i<r)
					 {
                        p=k>>1;//����߽߱��������߿϶�Ϊ0 ����������һ��һ��  ���൱����һ�ν����ұ�����ȥ������һλ ����߼�0
                        x=p&(1<<c);//��ʱ����cλ�Ƶ������0λ��
                        y=p&(1<<(c-1));  //��һ������ĺ���λ�� 
                         if(x==0&&y==0){                            
                           if(map[i+1][1]){
                             if(c!=1)
                              dp[i+1][1][p+(1<<c)+(1<<(c-1))]+=dp[i][j][k];//�����������ҵĲ�ͷ ��Ե�һԪ����˵��2λΪ1
                           }
                           else
                             dp[i+1][1][p]+=dp[i][j][k];//û�в�ͷ
                         }
                         if(x==0&&y!=0){//��������в�ͷ  Ҫô���¼�Ҫô����
                           if(map[i+1][1]){
                              if(c!=1) 
                               dp[i+1][1][p-x-y+(1<<(c-1))]+=dp[i][j][k];//����
                              dp[i+1][1][p-x-y+(1<<c)]+=dp[i][j][k];//����
                           }
                         }
                       }       
                      }
                      else{     
                        p=k;
                        x=p&(1<<(c-j));//ǰ����״̬
                        y=p&(1<<(c-j-1));  //�Ϻ���״̬ 
                        if(x==0&&y==0){//00
                          if(map[i][j+1]){//��ǰ����� 11
                             if(j<c-1)
                              dp[i][j+1][p-x-y+(1<<(c-j))+(1<<(c-j-1))]+=dp[i][j][k];//���º�����
                           }
                           else
                              dp[i][j+1][p-x-y]+=dp[i][j][k];
                        } 
                        else if(x!=0&&y!=0){//11
                          if(map[i][j+1]){
                             dp[i][j+1][p-x-y]+=dp[i][j][k];
                          }
                        }
                        else{//01 10 ��ʱ�µ�״̬ͬ������Ϊ10 ����01
                          if(map[i][j+1]){
                              if(j<c-1) 
                               dp[i][j+1][p-x-y+(1<<(c-j-1))]+=dp[i][j][k];//���������ͷ
                              dp[i][j+1][p-x-y+(1<<(c-j))]+=dp[i][j][k];//�������²�ͷ
                           }
                        }
                        
                      }
                   }
             }
         }
          printf(" There are %I64d ways to eat the trees.\n",dp[r][c][0]);//���һ�������Ҷ�Ӧ��������Ϊ������߽� ��Ȼ��ͷΪ0
}
int  main(){
     long t,i;
     scanf("%ld",&t);
     for(i=1;i<=t;i++){
        printf("Case %ld:",i);
        read();
        solve();
    }
    return 0;
}

