// hdu-1080-字符串比对.cpp : 定义控制台应用程序的入口点。
//f[i][j] = Max(f[i][j - 1] + Match('-', s2[j]), f[i - 1][j] + Match('-', s1[i]), f[i - 1][j - 1] + Match(s1[i], s2[j]))

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
#define NN 102
int Max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T, i, j, len1, len2;
    char s1[NN], s2[NN];
    int f[NN][NN], mat[NN][NN];
    mat['A']['A'] = mat['C']['C'] = mat['G']['G'] = mat['T']['T'] = 5;
    mat['A']['C'] = mat['C']['A'] = mat['A']['T'] = mat['T']['A'] = mat['-']['T'] = -1;
    mat['A']['G'] = mat['G']['A'] = mat['C']['T'] = mat['T']['C'] = mat['G']['T'] = mat['T']['G'] = mat['-']['G'] = -2;
    mat['-']['A'] = mat['C']['G'] = mat['G']['C'] = -3;
    mat['-']['C'] = -4;

    scanf("%d", &T);
    while (T--){
        scanf("%d%s%d%s", &len1, s1, &len2, s2);
        f[0][0] = 0;
        for (i = 1; i <= len1; i++)
            f[i][0] = f[i - 1][0] + mat['-'][s1[i - 1]];
        for (j = 1; j <= len2; j++)
            f[0][j] = f[0][j - 1] + mat['-'][s2[j - 1]];
        for (i = 1; i <= len1; i++){
            for (j = 1; j <= len2; j++){
                f[i][j] = Max(f[i][j - 1] + mat['-'][s2[j - 1]], Max(f[i - 1][j] + mat['-'][s1[i - 1]], f[i - 1][j - 1] + mat[s1[i - 1]][s2[j - 1]]));
            }
        }

        printf("%d\n", f[len1][len2]);
    }
    return 0;
}

