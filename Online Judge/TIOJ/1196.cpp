#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    vector<string> vec(n);
    vector<vector<ll>> result(n+1,vector<ll>(n+1));
    for(ll i=0;i<n;i++)
        cin>>vec[i];
    for(ll i=0;i<=n;i++)
        result[i][0]=result[0][i]=-1e9;
    result[1][1]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==1&&j==1) continue;
            if(vec[i-1][j-1]=='X') result[i][j]=-1e9;
            else if(vec[i-1][j-1]=='B') result[i][j]=max(result[i-1][j],result[i][j-1]);
            else result[i][j]=max(result[i-1][j],result[i][j-1])+(vec[i-1][j-1]-'0');
        }
    }
    if(result[n][n]<0) cout<<"X\n";
    else cout<<result[n][n]<<'\n';
}