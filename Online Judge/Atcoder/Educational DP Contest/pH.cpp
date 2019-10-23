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
    int h,w;
    cin>>h>>w;
    vector<vector<char>> v(h+1,vector<char>(w+1));
    vector<vector<int>> dp(h+1,vector<int>(w+1,0));
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin>>v[i][j];
    dp[1][1]=1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(i==1&&j==1) continue;
            if(v[i][j]!='#') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    cout<<dp[h][w]<<'\n';
}
