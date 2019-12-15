#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct DSU
{
    vector<int> v;
    DSU(int x)
    {
        v.resize(x);
        for(int i=1;i<x;i++)
            v[i]=i;
    }
    int find(int x)
    {
        if(v[x]==x) return x;
        return v[x]=find(v[x]);
    }
    void Union(int x,int y)
    {
        v[find(x)]=find(y);
    }
};

int main()
{
    AC
    int n,m,Q,cnt=0;
    cin>>n>>m;
    DSU ds(n+1);
    vector<pair<int,int>> v(m+1);
    vector<bool> b(m+1),tmp(n+1);
    stack<int,vector<int>> s,q;
    for(int i=1;i<=m;i++)
        cin>>v[i].first>>v[i].second;
    cin>>Q;
    while(Q--)
    {
        int t;
        cin>>t;
        b[t]=1;
        q.emplace(t);
    }
    for(int i=1;i<=m;i++)
        if(!b[i]) ds.Union(v[i].first,v[i].second);
    for(int i=1;i<=n;i++)
    {
        int x=ds.find(i);
        if(!tmp[x]) tmp[x]=1,cnt++;
    }
    s.emplace(cnt);
    while(q.size()>1)
    {
        int cur=q.top();
        q.pop();
        if(ds.find(v[cur].first)!=ds.find(v[cur].second)) cnt--;
        ds.Union(v[cur].first,v[cur].second);
        s.emplace(cnt);
    }
    for(;s.size();s.pop())
        cout<<s.top()<<'\n';
}