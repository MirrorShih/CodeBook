#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    unsigned long long n,dp[51][3];
    dp[1][0]=dp[1][1]=dp[1][2]=1;
    cin>>n;
    for(ll i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][2]=dp[i-1][1]+dp[i-1][2];
    }
    cout<<dp[n][0]+dp[n][1]+dp[n][2]<<'\n';
}