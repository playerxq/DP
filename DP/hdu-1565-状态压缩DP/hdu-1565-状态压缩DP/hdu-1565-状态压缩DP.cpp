// hdu-1565-状态压缩DP.cpp : 定义控制台应用程序的入口点。
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

void dfs(int id,int k,int p,int sum)//id 行号 k当前位置 p当前行的值 sum 当前行数字和
{
    if(k>=n)//超过n则可以记录这个状态
    {
        now[++now_size] = p;
        ans[now_size] = sum;
        return ;
    }
    dfs(id,k+2,p|(1<<k),sum+a[id][k]);//这个位置取了，那么就要加上这个位的二进制，通过或运算得出，这个位置取了的话，那么下一个要取的至少要跳两格
    dfs(id,k+1,p,sum);//这个位置不取并跳一格
}

void DP()
{
    int i,j,k;
    for(k = 1; k<=n; k++)
    {
        now_size = 0;
        dfs(k,0,0,0);//搜出此行的所有状态
        for(i = 1; i<=now_size; i++)
            dp[i] = 0;
        for(i = 1; i<=now_size; i++)//对当前k行的所有状态
        {
            for(j = 1; j<=pre_size; j++)//对前面行的所有状态
            {
                if(now[i]&pre[j]) continue;//相与为1，证明有相邻而不继续往下
                dp[i] = max(dp[i],tem[j]+ans[i]);//dp[i]为当前行选取状态为第i个时的最优结果。temp[j]为上一行选取状态为第j个时的最优结果 ans[i]为当前行状态第i个时对应的和
            }
        }
        for(i = 1; i<=now_size; i++)//目前这行的状态保存为上一行
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
        tem[1] = pre[1] = 0;//先取一个，但是位置并不确定，
        pre_size = 1;
        DP();
        int ans = 0;
        for(i = 1;i<=pre_size;i++)
        ans = max(ans,tem[i]);
        printf("%d\n",ans);
    }

    return 0;
}


