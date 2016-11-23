// leetcode-72-string distance.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int** dp = new int* [l1+1];
        for(int i = 0;i<l1+1;i++)
            dp[i] = new int[l2+1];
        for(int i = 0;i<l1+1;i++)
            for(int j = 0;j<l2+1;j++)
                dp[i][j] = l1+l2+2;
        for(int i = 0;i<l2+1;i++)
            dp[0][i] = i;
        for(int i = 0;i<l1+1;i++)
            dp[i][0] = i;
        for(int i = 1;i<l1+1;i++)
        {
            for(int j = 1;j<l2+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int m = (dp[i][j-1]>dp[i-1][j-1])?dp[i-1][j-1]:dp[i][j-1];
                    m = (m>dp[i-1][j])?dp[i-1][j]:m;
                    dp[i][j] = m+1;
                }
            }
        }
        return dp[l1][l2];
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
