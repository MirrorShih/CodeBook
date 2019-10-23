#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,m,r=0;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    vector<int> deg(n+1,0),dis(n+1,0);
    for(int i=0;i<m;i++)
    {
        int s,t;
        cin>>s>>t;
        v[s].emplace_back(t);
        deg[t]++;
    }
    queue<int> q;
    for(int i=1;i<v.size();i++)
        if(!deg[i]) q.push(i);
    while(q.size())
    {
        for(auto e:v[q.front()])
        {
            dis[e]=max(dis[e],dis[q.front()]+1);
            r=max(r,dis[e]);
            deg[e]--;
            if(!deg[e]) q.push(e);
        }
        q.pop();
    }
    cout<<r<<'\n';
}
