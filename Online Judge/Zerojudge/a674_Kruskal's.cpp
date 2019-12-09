#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct edge
{
    int u,v,w;
};

bool cmp(edge const& a, edge const& b)
{
    return a.w < b.w;
}

vector<edge> v;

struct DSU
{
    vector<int> v;

    DSU(int x)
    {
        v.resize(x);
        for(int i=1;i<x;i++)
            v[i] = i;
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
    int c,s,q,cnt=1;
    while(cin>>c>>s>>q&&c&&s&&q)
    {
        cout<<"Case #"<<cnt++<<'\n';
        v.clear();
        v.resize(s);
        for(auto &e:v)
            cin>>e.u>>e.v>>e.w;
        sort(v.begin(),v.end(),cmp);
        while(q--)
        {
            DSU d(c+1);
            bool b=0;
            int f,t;
            cin>>f>>t;
            for(auto e:v)
            {
                if(d.find(e.u)!=d.find(e.v)) d.Union(e.u,e.v);
                if(d.find(f)==d.find(t))
                {
                    cout<<e.w<<'\n';
                    b=1;
                    break;
                }
            }
            if(!b) cout<<"no path\n";
        }
        cout<<'\n';
    }
}
