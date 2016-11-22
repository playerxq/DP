// hdu-1693-轮廓线DP.cpp : 定义控制台应用程序的入口点。
//F[i,j,k]表示轮廓线在i行j列出外凸，轮廓线状态为k的方案数。
//与骨牌轮廓线相比，此题的状态应为列数+1  因为(i,j)位置的左侧竖线属于轮廓线的第(c-j-1)位  (i,j)的上面横线应是c-j位
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
             for(k=0;k<(1<<(c+1));k++) //c+1位
               if(dp[i][j][k])//开始判断j+1格或者i+1行第一格
			   {
                  if(j==c)//对j判断完全后的状态将赋值给下一行的第一个元素
				  {            
                     if(i<r)
					 {
                        p=k>>1;//最左边边界代表的竖边肯定为0 其他的与上一段一样  即相当于上一段将最右边竖线去掉右移一位 最左边加0
                        x=p&(1<<c);//此时左移c位移到最左边0位置
                        y=p&(1<<(c-1));  //第一格上面的横线位置 
                         if(x==0&&y==0){                            
                           if(map[i+1][1]){
                             if(c!=1)
                              dp[i+1][1][p+(1<<c)+(1<<(c-1))]+=dp[i][j][k];//加向下与向右的插头 则对第一元素来说首2位为1
                           }
                           else
                             dp[i+1][1][p]+=dp[i][j][k];//没有插头
                         }
                         if(x==0&&y!=0){//上面横线有插头  要么向下加要么向右
                           if(map[i+1][1]){
                              if(c!=1) 
                               dp[i+1][1][p-x-y+(1<<(c-1))]+=dp[i][j][k];//向右
                              dp[i+1][1][p-x-y+(1<<c)]+=dp[i][j][k];//向下
                           }
                         }
                       }       
                      }
                      else{     
                        p=k;
                        x=p&(1<<(c-j));//前竖线状态
                        y=p&(1<<(c-j-1));  //上横线状态 
                        if(x==0&&y==0){//00
                          if(map[i][j+1]){//当前格可行 11
                             if(j<c-1)
                              dp[i][j+1][p-x-y+(1<<(c-j))+(1<<(c-j-1))]+=dp[i][j][k];//向下和向右
                           }
                           else
                              dp[i][j+1][p-x-y]+=dp[i][j][k];
                        } 
                        else if(x!=0&&y!=0){//11
                          if(map[i][j+1]){
                             dp[i][j+1][p-x-y]+=dp[i][j][k];
                          }
                        }
                        else{//01 10 此时新的状态同样或者为10 或者01
                          if(map[i][j+1]){
                              if(j<c-1) 
                               dp[i][j+1][p-x-y+(1<<(c-j-1))]+=dp[i][j][k];//新增右向插头
                              dp[i][j+1][p-x-y+(1<<(c-j))]+=dp[i][j][k];//新增向下插头
                           }
                        }
                        
                      }
                   }
             }
         }
          printf(" There are %I64d ways to eat the trees.\n",dp[r][c][0]);//最后一个格子且对应的轮廓线为最下面边界 自然插头为0
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

