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
    double n;
    while(cin>>n&&n)
    {
        double r=0,t,mx=0,mn=11;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            r+=t;
            mx=max(mx,t);
            mn=min(mn,t);
        }
        r-=mx+mn;
        r/=(n-2);
        r+=1e-9;
        cout<<fixed<<setprecision(2)<<r<<'\n';
    }
}