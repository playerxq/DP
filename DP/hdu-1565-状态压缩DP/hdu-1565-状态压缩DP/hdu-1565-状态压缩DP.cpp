// hdu-1565-״̬ѹ��DP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int L = 20000;
int n,a[20][20];
int dp[L],tem[L];
int now[L],pre[L];
int ans[L],pre_size,now_size;

void dfs(int id,int k,int p,int sum)//id �к� k��ǰλ�� p��ǰ�е�ֵ sum ��ǰ�����ֺ�
{
    if(k>=n)//����n����Լ�¼���״̬
    {
        now[++now_size] = p;
        ans[now_size] = sum;
        return ;
    }
    dfs(id,k+2,p|(1<<k),sum+a[id][k]);//���λ��ȡ�ˣ���ô��Ҫ�������λ�Ķ����ƣ�ͨ��������ó������λ��ȡ�˵Ļ�����ô��һ��Ҫȡ������Ҫ������
    dfs(id,k+1,p,sum);//���λ�ò�ȡ����һ��
}

void DP()
{
    int i,j,k;
    for(k = 1; k<=n; k++)
    {
        now_size = 0;
        dfs(k,0,0,0);//�ѳ����е�����״̬
        for(i = 1; i<=now_size; i++)
            dp[i] = 0;
        for(i = 1; i<=now_size; i++)//�Ե�ǰk�е�����״̬
        {
            for(j = 1; j<=pre_size; j++)//��ǰ���е�����״̬
            {
                if(now[i]&pre[j]) continue;//����Ϊ1��֤�������ڶ�����������
                dp[i] = max(dp[i],tem[j]+ans[i]);//dp[i]Ϊ��ǰ��ѡȡ״̬Ϊ��i��ʱ�����Ž����temp[j]Ϊ��һ��ѡȡ״̬Ϊ��j��ʱ�����Ž�� ans[i]Ϊ��ǰ��״̬��i��ʱ��Ӧ�ĺ�
            }
        }
        for(i = 1; i<=now_size; i++)//Ŀǰ���е�״̬����Ϊ��һ��
        {
            tem[i] = dp[i];
            pre[i] = now[i];
        }
        pre_size = now_size;
    }
}

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i = 1; i<=n; i++)
            for(j = 0; j<n; j++)
                scanf("%d",&a[i][j]);
        tem[1] = pre[1] = 0;//��ȡһ��������λ�ò���ȷ����
        pre_size = 1;
        DP();
        int ans = 0;
        for(i = 1;i<=pre_size;i++)
        ans = max(ans,tem[i]);
        printf("%d\n",ans);
    }

    return 0;
}


