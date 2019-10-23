#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,dp[101]={0,1,5};
    for(ll i=3;i<101;i++)
        dp[i]=dp[i-1]+i*i;
    while(cin>>n&&n)
        cout<<dp[n]<<'\n';
}