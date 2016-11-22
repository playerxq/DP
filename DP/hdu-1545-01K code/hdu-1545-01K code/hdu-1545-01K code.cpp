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

__int64 dp[111][11][11];   // dp[i][j][k] 1:i�� 1��0�����j�� 0��1������k��
__int64 N,K,temp;  
inline void init()                          
{                              
    memset(dp,0,sizeof(dp));  
    dp[1][1][0]=1;       
    dp[1][0][1]=1;   
}  
void dpstart()  
{  
    init();  
    for(int i=2;i<=N;i++)  
    {  
        for(int j=1;j<=K;j++)  
        {  
            dp[i][0][j]=dp[i-1][1][j-1]+dp[i-1][0][j-1];//1������0������ ��������1 ����1������ɵĴ�����������    
            dp[i][j][0]=dp[i-1][j-1][1]+dp[i-1][j-1][0];//  
        }
        for(int x=1;x<K;x++)  
        {  
            for(int y=1;y<K;y++)  
            {  
                dp[i][x][y]=dp[i-1][x+1][y-1]+dp[i-1][x-1][y+1];  //����0����1
            }  
        }       
        for(int j=1;j<K;j++)  
        {         
            dp[i][K][j]=dp[i-1][K-1][j+1];  //��һ��1 ���ܼ�0 �����֮ǰ1��0��k+1��
            dp[i][j][K]=dp[i-1][j+1][K-1];  //��һ��0
        }  
    }  
    temp=0;  
    for(int i=0;i<=K;i++)  
    {  
        for(int j=0;j<=K;j++)  
        {  
            temp+=dp[N][i][j];  
        }  
    }                             
    cout<<temp<<endl;  
    return ;  
}  
int main()  
{   
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(cin>>N>>K)  
    {         
        dpstart();  
    }        
    return 0;  
}  