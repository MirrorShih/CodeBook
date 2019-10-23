#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,a,b,c;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3)),dp(n,vector<int>(3));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>v[i][j];
    dp[0][0]=v[0][0],dp[0][1]=v[0][1],dp[0][2]=v[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+v[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+v[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+v[i][2];
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<'\n';
}
