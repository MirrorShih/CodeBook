#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    string m,b;
    cin>>m>>b;
    vector<vector<ll>> dp(m.size()+1,vector<ll>(b.size()+1,0));
    for(ll i=1;i<=m.size();i++)
        for(ll j=1;j<=b.size();j++)
            if(m[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    ll t;
    cin>>t;
    if(dp[m.size()][b.size()]>=t) cout<<"kwa nini unaendesha\n";
    else cout<<"sitini na tisa\n";
}