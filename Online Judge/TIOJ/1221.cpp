#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    ll n,k,p,r=0;
    cin>>n>>k>>p;
    vector<ll> v(p);
    vector<queue<ll,list<ll>>> vq(n+1);
    for(ll i=0;i<p;i++)
        cin>>v[i],vq[v[i]].push(i);
    for(ll i=1;i<=n;i++)
        vq[i].push(1e9);
    unordered_set<ll> s;
    priority_queue<pair<ll,ll>> pq;
    for(ll i=0;i<p;i++)
    {
        if(s.find(v[i])==s.end()) s.insert(v[i]),r++;
        if(s.size()>k)
        {
            s.erase(pq.top().second);
            pq.pop();
        }
        vq[v[i]].pop();
        pq.push({vq[v[i]].front(),v[i]});
    }
    cout<<r<<'\n';
}