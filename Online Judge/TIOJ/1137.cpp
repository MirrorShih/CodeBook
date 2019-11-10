#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v;
vector<int> tag,low;
vector<bool> vertex;
int c=1,r=0;

void dfs(int x,int par)
{
    tag[x]=low[x]=c++;
    int child=0;
    for(auto e:v[x])
    {
        if(!tag[e])
        {
            child++;
            dfs(e,x);
            low[x]=min(low[e],low[x]);
            if(low[e]>=tag[x]&&x!=par) vertex[x]=1,r++;
        }
        else if(tag[e]<tag[x]&&e!=par) low[x]=min(low[x],low[e]);
    }
    if(x==par&&child>1) vertex[x]=1,r++;
}

int main()
{
    AC
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        c=1,r=0;
        v.clear(),tag.clear(),low.clear(),vertex.clear();
        v.resize(n+1),tag.resize(n+1),low.resize(n+1),vertex.resize(n+1);
        while(m--)
        {
            int f,t;
            cin>>f>>t;
            v[f].emplace_back(t);
            v[t].emplace_back(f);
        }
        dfs(1,1);
        cout<<r<<'\n';
        if(!r) cout<<'0';
        for(int i=1;i<=n;i++)
            if(vertex[i]) cout<<i<<' ';
        cout<<'\n';
    }
}
