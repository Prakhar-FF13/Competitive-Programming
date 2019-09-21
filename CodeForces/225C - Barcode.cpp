#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
const int INF=0x3f3f3f3f;
int a[maxn][maxn];
int cnt[maxn][2];
int dp[maxn][maxn][2];
char c[maxn][maxn];
int main()
{
    int m,n,x,y;
    scanf(" %d %d %d %d ",&m,&n,&x,&y);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            char x;
            scanf(" %c",&x);
            if(x=='#')cnt[j][1]++;
            else cnt[j][0]++;
        }
    }
    memset(dp,0x3f,sizeof(dp));
   for(int i=0;i<n;i++)
   {
        if(i==0) for(int k=0;k<2;k++) {
            dp[i][1][k]=cnt[i][k];
            continue;
        }
        for(int j=1;j<=i+1&&j<=y;j++)
        {
            if(j==1)
            {
                for(int k=x;k<=y;k++){
                    dp[i][j][0]=min(dp[i][j][0],dp[i-1][k][1]+cnt[i][0]);
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][0]+cnt[i][1]);
                }
            }
            else {
                dp[i][j][0]=dp[i-1][j-1][0]+cnt[i][0];
                dp[i][j][1]=dp[i-1][j-1][1]+cnt[i][1];
            }
        }
    }
    int ans=INF;
    for(int i=x;i<=y;i++)
    {
        ans=min(ans,dp[n-1][i][0]);
        ans=min(ans,dp[n-1][i][1]);
    }
    cout<<ans<<endl;
}
