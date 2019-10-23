#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll dp[51]={1,1,2,3},n;
    for(ll i=4;i<51;i++)
        dp[i]=dp[i-1]+dp[i-2];
    while(cin>>n&&n)
        cout<<dp[n]<<'\n';
}