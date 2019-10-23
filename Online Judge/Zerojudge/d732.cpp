#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,k;
    while(cin>>n>>k)
    {
        vector<ll> vec(n);
        for(ll i=0;i<n;i++)
            cin>>vec[i];
        for(ll i=0;i<k;i++)
        {
            ll temp;
            bool f=0;
            cin>>temp;
            ll l=0,r=n;
            while(l<r)
            {
                ll m=(l+r)>>1;
                if(vec[m]==temp)
                {
                    cout<<m+1<<'\n';
                    f=1;
                    break;
                }
                else if(vec[m]>temp) r=m;
                else l=m+1;
            }
            if(!f) cout<<"0\n";
        }
    }
}