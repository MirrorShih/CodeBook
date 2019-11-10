#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v;
vector<int> tag,low;
vector<bool> ver;
int c=1,r=0;

void dfs(int x,int par)
{
    int child=0;
    tag[x]=low[x]=c++;
    for(auto e:v[x])
    {
        if(!tag[e])
        {
            child++;
            dfs(e,x);
            low[x]=min(low[x],low[e]);
            if(low[e]>=tag[x]&&x!=par) ver[x]=1,r++;
        }
        else if(tag[e]<tag[x]&&e!=par) low[x]=min(low[x],low[e]);
    }
    if(x==par&&child>1) ver[x]=1,r++;
}

int main()
{
    AC
    int n,m,count=1;
    while(cin>>n>>m&&n&&m)
    {
        c=1,r=0;
        cout<<"Case #"<<count++<<':';
        v.clear(),tag.clear(),low.clear(),ver.clear();
        v.resize(n+1),tag.resize(n+1),low.resize(n+1),ver.resize(n+1);
        while(m--)
        {
            int f,t;
            cin>>f>>t;
            v[f].emplace_back(t);
            v[t].emplace_back(f);
        }
        dfs(1,1);
        cout<<r;
        if(!r) cout<<" 0";
        for(int i=1;i<=n;i++)
            if(ver[i]) cout<<' '<<i;
        cout<<'\n';
    }
}
