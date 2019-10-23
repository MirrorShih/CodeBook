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
    int m;
    cin>>m;
    vector<ll> dp(751,0);
    dp[0]=1;
    for(int i=1;i<751;i+=2)
        for(int j=i;j<751;j++)
            dp[j]+=dp[j-i];
    while(m--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }
}