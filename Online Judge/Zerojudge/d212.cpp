#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,dp[101]={1,1};
    for(ll i=2;i<101;i++)
        dp[i]=dp[i-1]+dp[i-2];
    while(cin>>n)
        cout<<dp[n]<<'\n';
}