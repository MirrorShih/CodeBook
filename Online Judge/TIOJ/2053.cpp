#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct martix
{
    ll m[2][2];

    martix operator*(martix a)
    {
        martix r;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                r.m[i][j]=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                {
                    r.m[i][j]=(r.m[i][j]+((m[i][k]%1000000007)*(a.m[k][j]%1000000007))%1000000007)%1000000007;
                }
        return r;
    }
}mar;

martix quickpow(int n)
{
    martix r;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(i==j) r.m[i][j]=1;
            else r.m[i][j]=0;
    for(;n;n>>=1)
    {
        if(n&1) r=r*mar;
        mar=mar*mar;
    }
    return r;
}

int main()
{
    AC
    ll x1,x2,a,b,n;
    cin>>x1>>x2>>a>>b>>n;
    mar.m[0][0]=b;
    mar.m[0][1]=1;
    mar.m[1][0]=a;
    mar.m[1][1]=0;
    martix r=quickpow(n-2);
    ll ans=((x1%1000000007)*(r.m[1][0]%1000000007))%1000000007;
    ans+=((x2%1000000007)*(r.m[0][0]%1000000007))%1000000007;
    ans%=1000000007;
    cout<<ans<<'\n';
}
