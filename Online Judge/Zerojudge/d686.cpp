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
    int n,l;
    while(cin>>l&&l)
    {
        cin>>n;
        vector<int> v(n+1);
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int i=1;i<=n;i++) cin>>v[i];
        v.emplace_back(l);
        for(int i=2;i<=n+1;i++)
            for(int j=0;j+i<=n+1;j++)
            {
                dp[j][j+i]=1e9;
                for(int k=j+1;k<j+i;k++)
                    dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k][j+i]+v[j+i]-v[j]);
            }
        cout<<"The minimum cutting is "<<dp[0][n+1]<<".\n";
    }
}