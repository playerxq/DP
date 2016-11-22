// hdu-1516-字符串DP.cpp : 定义控制台应用程序的入口点。
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

 char str1[100],str2[100];
 int p[101][101],o1[1000],o2[1000];
 char str[1000];
 int main()
 {
     int i,j,k,len1,len2,n,a;
     while(scanf("%s%s",str1,str2)!=EOF)
     {
         memset(p,0,sizeof(p));
         memset(o1,0,sizeof(o1));//记录位置
         memset(o2,0,sizeof(o2));//记录操作
         memset(str,0,sizeof(str));//记录字符
         len1 = strlen(str1);
         len2 = strlen(str2);
         for(i = 1;i <= len1;i ++)
			p[i][0] = i;
         for(i = 1;i <= len2;i ++)
			p[0][i] = i;
         for(i = 1;i <= len1;i ++)
			 for(j = 1;j <= len2;j ++)
			 {
				 if(str1[i-1] == str2[j-1])
					n = 0;
				 else
					n = 1;
				 p[i][j] = p[i-1][j-1]+n;
				 if(p[i][j] > p[i-1][j]+1)
					p[i][j] = p[i-1][j]+1;
				 if(p[i][j] > p[i][j-1]+1)
					p[i][j] = p[i][j-1]+1;
			 }
         printf("%d\n",p[len1][len2]);
         k = 1;
         for(i = len1,j = len2;;)//寻找路径
         {
             n = 0;
             if(str1[i-1] == str2[j-1]&&i >= 1&&j >= 1)
				n = 0;
             else
				n = 1;
             if(p[i][j] == p[i-1][j-1]+n&&i >= 1&&j >=1)
             {
                 if(n == 1)
                 {
                     o1[k] = 1;
                     o2[k] = i;
                     str[k] = str2[j-1];
                     k ++;
                 }
                 i -- ;j --;
             }
             else if(p[i][j] == p[i-1][j]+1&&i >= 1)
             {
                 o1[k] = 2;
                 o2[k] = i;
                 k ++;
                 i --;
             }
             else if(p[i][j] == p[i][j-1]+1&& j >= 1)
             {
                 o1[k] = 3;
                 o2[k] = i+1;
                 str[k] = str2[j-1];
                 k ++;
                 j --;
             }
             if(i == 0&&j == 0)
             break;
         }
         j = 1;
         for(i = k-1;i >= 1;i --)
         {
             if(o1[i] == 1)
				printf("%d Replace %d,%c\n",j++,o2[i],str[i]);
             else if(o1[i] == 2)
             {
                 printf("%d Delete %d\n",j++,o2[i]);
                for(a = i-1;a >= 1;a --)//位置变化
                 {
                    if(o2[a] >= o2[i])
						o2[a] --;
                }
            }
            else if(o1[i] == 3)
            {
                printf("%d Insert %d,%c\n",j++,o2[i],str[i]);
                for(a = i-1;a >= 1;a --)//位置变化
                {
                     if(o2[a] >= o2[i])
						o2[a] ++;
                }
            }
         }
     }
    return 0;
}

