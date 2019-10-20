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
    ll r=0;
    cin>>n;
    vector<vector<ll>> v(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            v[i][j]=v[i-1][j]+t;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ll tmp=0;
            for(int k=1;k<=n;k++)
            {
                if(tmp>=0)  tmp+=v[j][k]-v[i-1][k];
                if(tmp<0) tmp=v[j][k]-v[i-1][k];
                r=max(r,tmp);
            }
        }
    }
    cout<<r<<'\n';
}