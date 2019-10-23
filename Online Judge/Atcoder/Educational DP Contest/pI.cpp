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
    double r=0;
    cin>>n;
    vector<double> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int x=j,y=i-j;
            if(x) dp[x][y]+=dp[x-1][y]*v[i];
            if(y) dp[x][y]+=dp[x][y-1]*(1-v[i]);
        }
    }
    for(int i=n;i>n-i;i--) r+=dp[i][n-i];
    cout<<fixed<<setprecision(10)<<r<<'\n';
}
