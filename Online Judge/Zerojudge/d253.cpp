#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,dp[7500],v[5]={5,10,25,50};
    fill(dp,dp+7500,1);
    for(ll i=0;i<4;i++)
    {
        for(ll j=1;j<7500;j++)
        {
            if(j>=v[i]) dp[j]+=dp[j-v[i]];
        }
    }
    while(cin>>n)
    {
        cout<<dp[n]<<'\n';
    }
}