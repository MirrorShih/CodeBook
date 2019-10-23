#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int w,deg=0,val=0;
    vector<int> child;
};

int main()
{
    AC
    int t;
    cin>>t;
    while(t--)
    {
        int n,end,r=0;
        cin>>n;
        vector<node> v(n+1);
        for(int i=1;i<=n;i++)
        {
            int w,cnt;
            cin>>v[i].w>>cnt;
            while(cnt--)
            {
                int to;
                cin>>to;
                v[to].deg++;
                v[i].child.emplace_back(to);
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
            if(!v[i].deg) v[i].val=v[i].w,q.emplace(i);
        while(q.size())
        {
            int cur=q.front();
            q.pop();
            if(!v[cur].child.size()) r=max(r,v[cur].val);
            for(auto e:v[cur].child)
            {
                v[e].deg--;
                v[e].val=max(v[e].val,v[cur].val+v[e].w);
                if(!v[e].deg) q.emplace(e);
            }
        }
        cout<<r<<'\n';
    }
}