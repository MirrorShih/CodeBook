#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define lowbit(x) x&-x

ll n;

struct BIT
{
    vector<ll> v;
    void modify(ll x,ll val)
    {
        for(;x<v.size();x+=lowbit(x))
            v[x]+=val;
    }
    ll query(ll x)
    {
        ll t=0;
        for(;x;x-=lowbit(x))
            t+=v[x];
        return t;
    }
};

int main()
{
    AC
    ll num=1;
    while(cin>>n&&n)
    {
        cout<<"Case #"<<num++<<": ";
        ll r=0,rnk=1;
        BIT sum;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
            cin>>v[i];
        vector<ll> tmp(v.begin(),v.end());
        sort(tmp.begin(),tmp.end());
        tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
        for(auto &e:v)
            e=lower_bound(tmp.begin(),tmp.end(),e)-tmp.begin()+1;
        sum.v.resize(tmp.size()+1,0);
        for(ll i=n-1;i>=0;i--)
        {
            r+=sum.query(v[i]-1);
            sum.modify(v[i],1);
        }
        cout<<r<<'\n';
    }
}