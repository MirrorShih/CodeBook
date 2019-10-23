#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct ds
{
    vector<int> v;
    ds(int n)
    {
        for(int i=0;i<n;i++) v.emplace_back(i);
    }
    int Find(int x)
    {
        if(v[x]==x) return x;
        return v[x]=Find(v[x]);
    }
    void Union(int x,int y)
    {
        v[Find(y)]=Find(x);
    }
};

int main()
{
    AC
    int n,t;
    while(cin>>n)
    {
        int r=0;
        ds d(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>t;
            d.Union(i,t);
        }
        unordered_map<int,int> um;
        for(int i=1;i<=n;i++)
        {
            int F=d.Find(i);
            um[F]++;
            r=max(r,um[F]);
        }
        cout<<um.size()<<' '<<r<<'\n';
    }
}