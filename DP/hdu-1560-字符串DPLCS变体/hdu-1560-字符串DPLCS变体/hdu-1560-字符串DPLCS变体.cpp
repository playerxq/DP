// hdu-1560-�ַ���DPLCS����.cpp : �������̨Ӧ�ó������ڵ㡣
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
			++ h[a[i][j]];//ÿ���ַ���ԭ���д�x[i]��n[i]-1��ʣ�മ�еĳ��ִ���
        for(j = 0; j < 4; j ++) 
			max[j] = std::max(max[j], h[j]);//ÿ���ַ���ʣ�������ִ���
    }
    return max[0] + max[1] + max[2] + max[3];
}
int dfs(int d, int *ix)//ix��¼�����д���ǰdfs����ʼλ��
{
    if(Max(ix) > d) return 0;//ʣ���ַ����ʹ���d ����dfsÿ�ֲ���һ���ַ� ���ʣ���d�޷�����ʣ���max�ַ���  ��֦
    if(d == 0) return 1;
    int i, j, x[MAXN];
    for(i = 0; i < 4; i ++)//Ŀ�Ĵ���ǰ��Ҫ�ĸ��ַ���
    {
        for(j = 0; j < N; j ++)//��ÿ���ַ��� ������Ҫ���ַ�
        {
            if(ix[j] < n[j] && a[j][ix[j]] == i)//��j��������ʣ���ҵ�ǰ���ǵ��˵�j������ix[j]���ַ�i
                x[j] = ix[j] + 1;//����ǰ�ַ���ΪĿ�Ĵ����ַ�  j������һ��Ԫ��
            else x[j] = ix[j];//ʹ�ñ�Ĵ���
        }    
        if(dfs(d - 1, x)) return 1;
    }
    return 0;
}
void solve()
{
    int dep, ini[8] = {0};
    for(dep = 1; !dfs(dep, ini); dep ++);//�鿴��ǰ����ܷ�ϲ���Ŀ�Ĵ� ����dep
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

