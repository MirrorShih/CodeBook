#include<bits/stdc++.h>
using namespace std;

struct edge
{
    long from,to,value;
};

vector<edge> vec;
vector<long> ds;

void init_ds(long n)
{
    ds.reserve(n);
    for(int i=0;i<n;i++)
        ds.push_back(i);
}

long Find(long x)
{
    if(ds.at(x)==x) return x;
    return ds.at(x)=Find(ds.at(x));
}

long Union(long x,long y)
{
    long X=Find(x),Y=Find(y);
    ds.at(X)=Y;
}

bool Same(long x,long y)
{
    return (Find(x)==Find(y));
}

bool cmp(edge a,edge b)
{
    return a.value<b.value;
}

long Kruskal()
{
    sort(vec.begin(),vec.end(),cmp);
    long result=0;
    for(auto e:vec)
    {
        if(Same(e.from,e.to)) continue;
        Union(e.from,e.to);
        result+=e.value;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    long n,m;
    while(cin>>n>>m)
    {
        vec.resize(m);
        init_ds(n);
        for(long i=0;i<m;i++)
        {
            cin>>vec.at(i).from>>vec.at(i).to>>vec.at(i).value;
        }
        long r=Kruskal();
        for(long i=1;i<n;i++)
            if(!Same(0,i))
                r=-1;
        cout<<r<<'\n';
        vec.clear();
        ds.clear();
    }
}