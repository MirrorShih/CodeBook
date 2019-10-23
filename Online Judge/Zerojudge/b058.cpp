#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int val,deg=0,mx=0;
    bool tag=0;
    vector<int> child;
    vector<int> par;
};

vector<node> v;

int dfs(int x)
{
    int r=0;
    if(v[x].tag) return 0;
    v[x].tag=1;
    for(auto e:v[x].par)
        r+=dfs(e);
    r++;
    return r;
}

int main()
{
    AC
    int n,m;
    while(cin>>n>>m)
    {
        int r=0,ans=0;
        v.clear();
        v.resize(n+1);
        vector<int> back;
        for(int i=1;i<=n;i++) cin>>v[i].val;
        for(int i=0;i<m;i++)
        {
            int f,t;
            cin>>f>>t;
            v[f].child.emplace_back(t);
            v[t].deg++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
            if(!v[i].deg) q.emplace(i),v[i].mx=v[i].val;
        while(q.size())
        {
            int cur=q.front();
            q.pop();
            if(!v[cur].child.size()&&v[cur].mx>=r)
            {
                if(r<v[cur].mx) back.clear();
                r=v[cur].mx;
                back.emplace_back(cur);
            }
            for(auto e:v[cur].child)
            {
                v[e].deg--;
                if(v[e].mx<=v[cur].mx+v[e].val)
                {
                    if(v[e].mx<v[cur].mx+v[e].val) v[e].par.clear();
                    v[e].mx=v[cur].mx+v[e].val;
                    v[e].par.emplace_back(cur);
                }
                if(!v[e].deg) q.emplace(e);
            }
        }
        for(auto e:back) ans+=dfs(e);
        cout<<ans<<'\n';
    }
}