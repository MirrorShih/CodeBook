#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n;
    while(cin>>n)
    {
        vector<ll> dp(101,0);
        while(n--)
        {
            ll v,c;
            cin>>v>>c;
            for(ll j=100;j>=v;j--)
                dp[j]=max(dp[j],dp[j-v]+c);
        }
        cout<<dp[100]<<'\n';
    }
}