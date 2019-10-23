#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,k;
    cin>>n>>k;
    vector<int> v(n),dp(n,1e9);
    for(int i=0;i<n;i++)
        cin>>v[i];
    dp[0]=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<=k;j++)
            if(i-j>=0) dp[i]=min(dp[i-j]+abs(v[i]-v[i-j]),dp[i]);
    cout<<dp[n-1]<<'\n';
}