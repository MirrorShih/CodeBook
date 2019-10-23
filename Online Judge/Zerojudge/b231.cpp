#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n,r=0,t=0;
    cin>>n;
    priority_queue<pair<ll,ll>> pq;
    for(ll i=0;i<n;i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        pq.push({t2,t1});
    }
    for(;pq.size();pq.pop())
    {
        t+=pq.top().second;
        r=max(r,t+pq.top().first);
    }
    cout<<r<<'\n';
}