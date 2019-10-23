#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> vec;

ll f(ll m)
{
    ll dis=0,count=0;
    for(ll i=0;i<vec.size();i++)
    {
        if(dis<vec[i])
        {
            dis=vec[i]+(m<<1);
            count++;
        } 
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vec.resize(n);
        for(ll i=0;i<n;i++)
            cin>>vec[i];
        sort(vec.begin(),vec.end());
        if(k==1) cout<<((vec[n-1]-vec[0]+1)>>1)<<'\n';
        else
        {
            ll l=0,r=(vec[n-1]-vec[0]+1)>>1;
            while(l<r)
            {
                ll m=(l+r)>>1;
                if(f(m)<=k) r=m;
                else l=m+1;
            }
            cout<<r<<'\n';
        }
        vec.clear();
    }
}