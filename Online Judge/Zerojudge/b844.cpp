#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,q;
    while(cin>>n>>q)
    {
        vector<ll> vec(n);
        for(ll i=0;i<n;i++)
            cin>>vec[i];
        sort(vec.begin(),vec.end());
        for(ll i=0;i<q;i++)
        {
            ll temp;
            cin>>temp;
            cout<<(((upper_bound(vec.begin(),vec.end(),temp)-vec.begin())&1)?1:0)<<'\n';
        }
    }
}