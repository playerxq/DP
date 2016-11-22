// hdu-1560-字符串DPLCS变体.cpp : 定义控制台应用程序的入口点。
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
#define MAXN 8
#define MAXL 5
int N, n[MAXN], a[MAXN][MAXL];
char ch[128];
void init()
{
    int i, j;
    char b[10];
    scanf("%d", &N);
    for(i = 0; i < N; i ++)
    {
        scanf("%s", b);
        n[i] = strlen(b);
        for(j = 0; j < n[i]; j ++) a[i][j] = ch[b[j]];
    }
}
int Max(int *x)
{
    int i, j, h[4], max[4] = {0};
    for(i = 0; i < N; i ++)
    {
        memset(h, 0, sizeof(h));
        for(j = x[i]; j < n[i]; j ++) 
			++ h[a[i][j]];//每个字符在原串中从x[i]到n[i]-1即剩余串中的出现次数
        for(j = 0; j < 4; j ++) 
			max[j] = std::max(max[j], h[j]);//每个字符的剩余最多出现次数
    }
    return max[0] + max[1] + max[2] + max[3];
}
int dfs(int d, int *ix)//ix记录了所有串当前dfs的起始位置
{
    if(Max(ix) > d) return 0;//剩余字符数和大于d 由于dfs每轮产生一个字符 因此剩余的d无法产生剩余的max字符数  减枝
    if(d == 0) return 1;
    int i, j, x[MAXN];
    for(i = 0; i < 4; i ++)//目的串当前需要哪个字符？
    {
        for(j = 0; j < N; j ++)//对每个字符串 查找需要的字符
        {
            if(ix[j] < n[j] && a[j][ix[j]] == i)//第j个串还有剩余且当前考虑到了第j个串的ix[j]号字符i
                x[j] = ix[j] + 1;//将当前字符作为目的串的字符  j串后移一个元素
            else x[j] = ix[j];//使用别的串的
        }    
        if(dfs(d - 1, x)) return 1;
    }
    return 0;
}
void solve()
{
    int dep, ini[8] = {0};
    for(dep = 1; !dfs(dep, ini); dep ++);//查看当前深度能否合并出目的串 长度dep
		printf("%d\n", dep);
}
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    ch['A'] = 0, ch['T'] = 1, ch['C'] = 2, ch['G'] = 3;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();    
    }
    return 0;    
}

