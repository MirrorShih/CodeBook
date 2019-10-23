#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n;
    cin>>n;
    vector<int> v(n),dp(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    dp[0]=0,dp[1]=abs(v[1]-v[0]);
    for(int i=2;i<n;i++)
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    cout<<dp[n-1]<<'\n';
}