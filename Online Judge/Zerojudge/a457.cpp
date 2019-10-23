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
    void modify(int x,int val)
    {
        for(;x<v.size();x+=lowbit(x))
            v[x]+=val;
    }
    ll query(int x)
    {
        ll r=0;        
        for(;x;x-=lowbit(x))
            r+=v[x];
        return r;
    }
};

int main()
{
    AC
    int k,m;
    ll r=0;
    cin>>k>>m;
    BIT sum;
    vector<pair<int,int>> v(k);
    vector<int> tmp(k);
    for(int i=0;i<k;i++)
        cin>>v[i].first;
    for(int i=0;i<k;i++)
        cin>>v[i].second,tmp[i]=v[i].second;
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    for(auto &e:v)
        e.second=lower_bound(tmp.begin(),tmp.end(),e.second)-tmp.begin()+1;
    sum.v.resize(tmp.size()+1);
    tmp.clear();
    sort(v.begin(),v.end());
    for(int i=k-1;i>=0;i--)
    {
        r+=sum.query(v[i].second-1);
        sum.modify(v[i].second,1);
    }
    cout<<r<<'\n';
}