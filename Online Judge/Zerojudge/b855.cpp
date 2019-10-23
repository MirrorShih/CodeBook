#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> vec(n);
        ll total=0;
        for(ll i=0;i<n;i++)
        {
            cin>>vec[i];
            total+=vec[i];
        }
        ll half=total/2;
        vector<ll> dp(half+1,0);
        for(ll i=0;i<n;i++)
            for(ll j=half;j>=vec[i];j--)
                dp[j]=max(dp[j-vec[i]]+vec[i],dp[j]);
        cout<<dp[half]*dp[half]+(total-dp[half])*(total-dp[half])<<'\n';
    }
}