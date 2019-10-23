#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v;
vector<bool> vis;

bool dfs(const int &f,const int &t)
{
    vis[f]=1;
    bool r=0;
    if(f==t) return 1;
    for(auto e:v[f])
        if(!vis[e]) r|=dfs(e,t);
    return r;
}

int main()
{
    AC
    int n,m,f,t;
    while(cin>>n>>m)
    {
        v.clear();
        vis.clear();
        v.resize(n+1);
        vis.resize(n+1,0);
        for(int i=0;i<m;i++)
        {
            cin>>f>>t;
            v[f].emplace_back(t);
        }
        cin>>f>>t;
        cout<<(dfs(f,t)?"Yes!!!":"No!!!")<<'\n';
    }
}