#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n;
    cin>>n;
    vector<int> v(n+1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<n;i++)
        dp[i][i]=dp[i][i+1]=0;
    for(int i=1;i<n;i++)
        for(int j=1;j+i<=n;j++)
            for(int k=j;k<=j+i;k++)
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k][j+i]+v[j]*v[k]*v[j+i]);
    cout<<dp[1][n]<<'\n';
}