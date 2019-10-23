#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n;
    cin>>n;
    vector<ll> v(n+1),sum(n+1);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++) cin>>v[i],sum[i]=sum[i-1]+v[i];
    for(int i=1;i<n;i++)
        for(int j=1;j+i<=n;j++)
        {
            dp[j][j+i]=1e18;
            for(int k=j;k<j+i;k++)
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
            dp[j][j+i]+=sum[j+i]-sum[j-1];
        }
    cout<<dp[1][n]<<'\n';
}
