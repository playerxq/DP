// uva-10401-injured queen problem.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int MAXN = 15+5;
char str[MAXN];
int boa[MAXN];
long long dp[MAXN][MAXN];
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    while (scanf("%s", str) != EOF)
    {
        int n = strlen(str);
        for (int i = 0; i < n; i++)//����������
        {
            if (str[i] == '?')
                boa[i+1] = 0;//boa[i]Ϊ��i��boa[i]���лʺ�
            else if ('1' <= str[i] && str[i] <= '9')
                boa[i+1] = str[i]-'0';
            else if ('A' <= str[i] && str[i] <= 'F')
                boa[i+1] = str[i]-'A'+10;
        }
        memset(dp, 0, sizeof(dp));
        if (boa[1])//��һ���лʺ���boa[1]�д�
            dp[boa[1]][1] = 1;
        else
            for (int i = 1; i <= n; i++)//��������λ�ö����Է���
                dp[i][1] = 1;
        for (int c = 2; c <= n; c++)//��ÿһ��
        {
            if (boa[c])//��ǰ���лʺ�  ��ֻ�ܷ�һ�� ��ֻ����ǰһ����Ӧ��Χ���������չ
            {
                for (int i = 1; i <= n; i++)
                {
                    if (boa[c]-1 <= i && i <= boa[c]+1)
                        continue;
                    dp[boa[c]][c] += dp[i][c-1];
                }
                continue;
            }
			//��ǰ��û�лʺ�  ��ÿ�п��Է��ûʺ���ǰһ�е���Ӧ�ж���
            for (int r = 1; r <= n; r++)
                for (int i = 1; i <= n; i++)//ǰһ��������
                {
                    if (r-1 <= i && i <= r+1)
                        continue;
                    dp[r][c] += dp[i][c-1];
                }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dp[i][n];
        printf("%lld\n", ans);
    }
    return 0;
}