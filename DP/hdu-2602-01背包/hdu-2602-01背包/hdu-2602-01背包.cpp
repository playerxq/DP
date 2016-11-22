// hdu-2602-01����.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[i][v]��ʾǰi����Ʒǡ����һ������Ϊv�ı������Ի�õ�����ֵ��
//����״̬ת�Ʒ��̱��ǣ�
//dp[i][v]=max{dp[i-1][v],dp[i-1][v-cost[i]]+value[i]}

#include "stdafx.h"
#include<iostream>
using namespace std;
int dp[1000][1000];

int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    int t,n,v,i,j;
    int va[1000],vo[1000];
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(i=1;i<=n;i++)
            cin>>va[i];
        for(i=1;i<=n;i++)
            cin>>vo[i];
        memset(dp,0,sizeof(dp));//��ʼ������
         for(i=1;i<=n;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(vo[i]<=j)//��ʾ��i����Ʒ�������СΪj�ı�����
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);//��i����Ʒ�������ôǰi-1����Ʒ���ܻ����Ҳ������Ϊʣ��ռ䲻���޷�����
                else //��i����Ʒ�޷�����
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][v]<<endl;
    }
    return 0;
}

