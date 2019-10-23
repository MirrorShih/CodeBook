#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long> vec;

long Find(long x)
{
    if(vec.at(x)==x) return x;
    return vec.at(x)=Find(vec.at(x));
}

void Union(long x,long y)
{
    long X=Find(x),Y=Find(y);
    vec.at(X)=Y;
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    long n,m;
    long time=0;
    while(cin>>n>>m)
    {
        if(!n&&!m)  break;
        time++;
        vec.reserve(n);
        for(long i=0;i<n;i++)
            vec.push_back(i);
        for(long i=0;i<m;i++)
        {
            long x,y;
            cin>>x>>y;
            Union(x-1,y-1);
        }
        for(long i=0;i<n;i++)
            Find(i);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        cout<<"Case "<<time<<": "<<vec.size()<<"\n";
        vec.clear();
    }
}