#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> vec;
ll n,k;

bool check(ll m)
{
    ll num=0,count=0;
    for(ll i=0;i<vec.size();i++)
    {
        if(vec[i]>num)
        {
            num=vec[i]+m;
            count++;
        }
    }
    if(count>k) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n>>k)
    {
        vec.resize(n);
        for(ll i=0;i<n;i++)
            cin>>vec[i];
        sort(vec.begin(),vec.end());
        if(k==1) cout<<vec[n-1]-vec[0]<<'\n';
        else
        {
            ll l=1,r=(vec[n-1]-vec[0])/k+1;
            while(l<r)
            {
                ll m=(l+r)>>1;
                if(check(m)) r=m;
                else l=m+1;
            }
            cout<<r<<'\n';
        }
        vec.clear();
    }
}