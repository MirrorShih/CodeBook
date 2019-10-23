#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,w;
    cin>>n>>w;
    vector<ll> dp(w+1,0);
    for(int i=0;i<n;i++)
    {
        int wei,val;
        cin>>wei>>val;
        for(int j=w;j>=wei;j--)
            dp[j]=max(dp[j],dp[j-wei]+val);
    }
    cout<<dp[w]<<'\n';
}
