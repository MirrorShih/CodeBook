#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,m,dp[201][201];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(ll i=1;i<201;i++)
        for(ll j=1;j<201;j++)
            dp[i][j]=(dp[i][j-1]*i+dp[i-1][j-1])%1000000;
    while(cin>>n>>m&&n&&m)
    {
        ll r=0;
        for(ll i=1;i<=n;i++)
            r=(r+dp[i][m])%1000000;
        cout<<r<<'\n';
    }
}