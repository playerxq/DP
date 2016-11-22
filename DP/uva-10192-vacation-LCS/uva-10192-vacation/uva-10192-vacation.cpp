// uva-10192-vacation.cpp : 定义控制台应用程序的入口点。
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
const int N=105;
int main()
{
    int t_cnt=0,map[N][N];
    char str1[N],str2[N];
    while(gets(str1))
    {
        if(strcmp(str1,"#")==0) break;

        gets(str2);
        memset(map,0,sizeof(map));
        int len1=strlen(str1);
        int len2=strlen(str2);
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(str1[i]==str2[j])
                {
                    map[i+1][j+1]=max(map[i+1][j+1],map[i][j]+1);
                }
                else map[i+1][j+1]=max(map[i+1][j],map[i][j+1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",++t_cnt,map[len1][len2]);
    }
    return 0;
}


