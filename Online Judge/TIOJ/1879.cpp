#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v,bcc;
vector<pair<int,int>> edge;
vector<int> low,tag;
int c=1;
stack<int> s;

void dfs(int x,int be)
{
    low[x]=tag[x]=c++,s.emplace(x);
    for(auto e:v[x])
    {
        int v=edge[e].second;
        if(!tag[v])
        {
            dfs(v,e^1);
            low[x]=min(low[x],low[v]);
            if(low[v]>tag[x])
            {
                bcc.resize(bcc.size()+1);
                while(s.top()!=v)
                {
                    bcc[bcc.size()-1].emplace_back(s.top());
                    s.pop();
                }
                bcc[bcc.size()-1].emplace_back(s.top());
                s.pop();
                sort(bcc[bcc.size()-1].begin(),bcc[bcc.size()-1].end());
            }
        }
        else if(tag[v]<tag[x]&&e!=be) low[x]=min(low[x],low[v]);
    }
}

int main()
{
    AC
    int n,m,f,t,num=1;
    cin>>n>>m;
    v.resize(n),low.resize(n),tag.resize(n);
    for(int i=0;i<m;i++)
    {
        cin>>f>>t;
        v[f].emplace_back(edge.size());
        edge.emplace_back(f,t);
        v[t].emplace_back(edge.size());
        edge.emplace_back(t,f);
    }
    dfs(0,-1);
    bcc.resize(bcc.size()+1);
    while(s.size())
    {
        bcc[bcc.size()-1].emplace_back(s.top());
        s.pop();
    }
    sort(bcc[bcc.size()-1].begin(),bcc[bcc.size()-1].end());
    sort(bcc.begin(),bcc.end());
    for (auto e:bcc)
    {
        cout<<num++<<": ";
        for(auto each:e)
            cout<<each<<' ';
        cout<<'\n';
    }
}
