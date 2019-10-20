#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

bool y=1;
vector<vector<int>> v;
vector<int> color;
vector<bool> vis;

void dfs(int x)
{
    if(vis[x]) return;
    if(!y) return;
    vis[x]=1;
    for(auto e:v[x])
    {
        if(!color[e]) color[e]=color[x]*-1;
        else if(color[e]==color[x])
        {
            y=0;
            return;
        }
        if(!vis[e]) dfs(e);
    }
}

int main()
{
    AC
    int n,m,f,t;
    while(cin>>n>>m&&(n||m))
    {
        y=1;
        v.resize(n+1),color.resize(n+1),vis.resize(n+1);
        for(int i=1;i<=n;i++) color[i]=0,v[i].clear(),vis[i]=0;
        for(int i=0;i<m;i++)
        {
            cin>>f>>t;
            v[f].emplace_back(t),v[t].emplace_back(f);
        }
        for(int i=1;i<=n;i++) if(!color[i]) color[i]=1,dfs(i);
        cout<<(y?"Yes\n":"No\n");
    }
}