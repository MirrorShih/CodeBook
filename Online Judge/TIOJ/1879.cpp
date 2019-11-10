#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<vector<int>> v,bcc;
vector<int> low,tag;
vector<unordered_map<int,int>> vn;
int c=1,num=0;
stack<int> s;

void dfs(int x,int par)
{
    low[x]=tag[x]=c++,s.emplace(x);
    for(auto e:v[x])
    {
        if(!tag[e])
        {
            dfs(e,x);
            low[x]=min(low[x],low[e]);
            if(low[e]>tag[x])
            {
                bcc.resize(num+1);
                while(s.size()&&s.top()!=e)
                {
                    bcc[num].emplace_back(s.top());
                    s.pop();
                }
                bcc[num].emplace_back(s.top());
                s.pop();
                sort(bcc[num].begin(), bcc[num].end());
                num++;
            }
        }
        else if(e!=par||(e==par&&vn[x][e]>1)) low[x]=min(low[x],low[e]);
    }
}

int main()
{
    AC
    int n,m,f,t;
    cin>>n>>m;
    v.resize(n),low.resize(n),tag.resize(n),vn.resize(n);
    while(m--)
    {
        cin>>f>>t;
        v[f].emplace_back(t);
        v[t].emplace_back(f);
        vn[f][t]++;
        vn[t][f]++;
    }
    dfs(f,f);
    bcc.resize(num+1);
    while(s.size())
    {
        bcc[num].emplace_back(s.top());
        s.pop();
    }
    sort(bcc[num].begin(), bcc[num].end());
    sort(bcc.begin(),bcc.end());
    for(int i=0;i<=num;i++)
    {
        cout<<i+1<<": ";
        for(auto e:bcc[i])
            cout<<e<<' ';
        cout<<'\n';
    }
}
