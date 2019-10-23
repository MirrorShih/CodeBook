#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v,dou;
vector<pair<int, int>> ti;
vector<int> dep;
int L,cou=1;

void dfs(int x,int par)
{
    ti[x].first = cou++;
    dou[x][0]=par;
    for(int i=1;i<=L;i++) dou[x][i]=dou[dou[x][i-1]][i-1];
    for(auto e:v[x]) dep[e]=dep[x]+1,dfs(e,x);
    ti[x].second = cou++;
}

bool anc(int x,int y)
{
    return ti[x].first<=ti[y].first&&ti[x].second>=ti[y].second;
}

int LCA(int x,int y)
{
    if(anc(x,y)) return x;
    for(int i=L;i>=0;i--)
        if(!anc(dou[x][i],y)) x=dou[x][i];
    return dou[x][0];
}

int main()
{
    AC
    int n,q,t;
    cin >> n >> q;
    L=log2(n)+1;
    v.resize(n+1),ti.resize(n+1),dou.resize(n+1,vector<int>(L+1)),dep.resize(n+1);
    for(int i=1;i<=n;i++)
        while(cin>>t&&t) v[i].emplace_back(t);
    dfs(1,1);
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int t=LCA(x,y);
        cout<<t<<' '<<dep[x]-dep[t]+dep[y]-dep[t]<<'\n';
    }
}