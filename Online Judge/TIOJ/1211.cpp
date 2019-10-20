#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct ds
{
    vector<int> v;
    ds(int n)
    {
        for(int i=0;i<n;i++) v.emplace_back(i);
    }
    int Find(int x)
    {
        if(v[x]==x) return x;
        return v[x]=Find(v[x]);
    }
    void Union(int x,int y)
    {
        v[Find(y)]=Find(x);
    }
};

struct edge
{
    int f,t,w;
    bool operator<(const edge &e)
    {
        return w<e.w;
    }
};

int main()
{
    AC
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m) break;
        bool b=1;
        int r=0;
        ds d(n+1);
        vector<edge> v(m);
        for(int i=0;i<m;i++) cin>>v[i].f>>v[i].t>>v[i].w;
        sort(v.begin(),v.end());
        for(auto e:v)
        {
            if(d.Find(e.f)==d.Find(e.t)) continue;
            r+=e.w;
            d.Union(e.t,e.f);
        }
        for(int i=1;i<=n;i++)
        {
            if(d.Find(1)!=d.Find(n))
            {
                b=0;
                break;
            }
        }
        if(b) cout<<r<<'\n';
        else cout<<"-1\n";
    }
}