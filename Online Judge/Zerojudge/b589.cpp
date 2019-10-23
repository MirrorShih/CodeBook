#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n;
    while(cin>>n&&n)
    {
        vector<ll> vec(n),dp(n+2);
        for(ll i=0;i<n;i++)
            cin>>vec[i];
        for(ll i=0;i<n;i++)
        {
            dp[i+1]=max(dp[i+1],dp[i]+vec[i]);
            dp[i+2]=max(dp[i+2],dp[i]+2*vec[i]);
        }
        cout<<max(dp[n],dp[n+1])<<'\n';
    }
}