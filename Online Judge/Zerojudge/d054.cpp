#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll t,dp[41];
    dp[0]=dp[1]=1;dp[2]=5;
    for(ll i=3;i<41;i++)
        dp[i]=dp[i-1]+4*dp[i-2]+2*dp[i-3];
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }
}