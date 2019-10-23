#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define lowbit(x) x&(-x)

int n;
ll sum[500001];
struct bit
{
    ll c[500001];
    void update(int p,int val)
    {
        for(;p<=n;p+=lowbit(p))
            c[p]+=val;
    }
    ll query(int p)
    {
        ll r=0;
        for(;p>0;p-=lowbit(p))
            r+=c[p];
        return r;
    }
} c1,c2;

int main()
{
    AC
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        sum[i]=sum[i-1]+t;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int v,x,y,k;
        cin>>v;
        if(v==1) cin>>x>>y>>k,c1.update(x,k),c1.update(y+1,-k),c2.update(x,k*x),c2.update(y+1,-k*(y+1));
        else cin>>x>>y,cout<<sum[y]+(y+1)*c1.query(y)-c2.query(y)-sum[x-1]-x*c1.query(x-1)+c2.query(x-1)<<'\n';
    }
}