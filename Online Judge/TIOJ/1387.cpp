#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,t;
    cin>>n;
    vector<pair<ll,ll>> vec;
    vector<ll> dp(10001,0);
    for(ll i=0;i<n;i++)
    {
        ll w,m,c;
        cin>>w>>m>>c;
        while(c--) vec.push_back({w,m});
    }
    cin>>t;
    for(ll i=0;i<vec.size();i++)
        for(ll j=t;j>=vec[i].first;j--)
            dp[j]=max(dp[j],dp[j-vec[i].first]+vec[i].second);
    cout<<dp[t]<<'\n';
}