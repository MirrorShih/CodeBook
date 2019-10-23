#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,dp[26][26];
    memset(dp,0,sizeof(dp));
    fill(dp[0],dp[0]+26,1);
    for(ll i=1;i<26;i++)
        for(ll j=i;j<26;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    while(cin>>n)
        cout<<dp[n][n]<<'\n';
}