#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,t,l;
    cin>>n>>t>>l;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++)
        cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(),vec.end(),greater<pair<ll,ll>>());
    vector<vector<ll>> dp(l+1,vector<ll>(t+1,0));
    for(ll i=0;i<n;i++)
        for(ll j=l;j>=1;j--)
            for(ll k=t;k>=vec[i].first*j;k--)
                dp[j][k]=max(dp[j][k],dp[j-1][k-vec[i].first*j]+vec[i].second);
    ll ans=0;
    for(ll i=0;i<=l;i++)
        ans=max(ans,*max_element(dp[i].begin(),dp[i].end()));
    cout<<ans<<'\n';
}