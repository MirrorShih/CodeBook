#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    ll l1=s1.size(),l2=s2.size(),l3=s3.size();
    vector<vector<vector<ll>>> dp(l1+1,vector<vector<ll>>(l2+1,vector<ll>(l3+1,0)));
    for(ll i=1;i<=l1;i++)
        for(ll j=1;j<=l2;j++)
            for(ll k=1;k<=l3;k++)
                if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
    cout<<dp[l1][l2][l3]<<'\n';
}