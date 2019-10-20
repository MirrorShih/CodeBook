#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define lowbit(x) x&-x

struct BIT
{
    vector<int> v;
    BIT(int n)
    {
        v.resize(n);
    }
    int query(int x)
    {
        int r=0;
        for(;x;x-=lowbit(x))
            r=max(r,v[x]);
        return r;
    }
    void modify(int x,int val)
    {
        for(;x<v.size();x+=lowbit(x))
            v[x]=max(v[x],val);
    }
};

int main()
{
    AC
    int n,t,r=0;
    cin>>n;
    BIT sum(n+1);
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        v.emplace_back(t);
    }
    vector<ll> tmp(v.begin(),v.end());
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    for(auto &e:v) e=lower_bound(tmp.begin(),tmp.end(),e)-tmp.begin()+1;
    for(int i=0;i<n;i++)
    {
        int temp=sum.query(v[i]-1)+1;
        r=max(r,temp);
        sum.modify(v[i],temp);
    }
    cout<<r<<'\n';
}