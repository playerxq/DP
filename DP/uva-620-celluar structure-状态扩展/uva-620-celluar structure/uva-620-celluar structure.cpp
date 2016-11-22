// uva-620-celluar structure.cpp : 定义控制台应用程序的入口点。
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
#define N 105  
char s[N];  
char ans[4][20] = {"MUTANT","SIMPLE","FULLY-GROWN","MUTAGENIC"};  
int dfs(int a, int b)  
{  
    if(s[a]=='A'&&a==b-1) return 1;  
    if(s[b-2]=='A'&&s[b-1]=='B'&&dfs(a,b-2)!=0) return 2;  
    if(s[a]=='B'&&s[b-1]=='A'&&dfs(a+1,b-1)!=0) return 3;  
    return 0;  
}  
int main ()  
{  
    int cas;  
    scanf("%d",&cas); getchar();  
    while(cas--)  
    {  
        scanf("%s",s);getchar();  
        int len = strlen(s);  
        printf("%s\n",ans[dfs(0,len)]);  
    }  
    return 0;  
} 

