#include<bits/stdc++.h>
using namespace std;

struct edge
{
    long long start,end;
};

vector<edge> vec;

bool cmp(edge a,edge b)
{
    if(a.start==b.start) return a.end<b.end;
    else return a.start<b.start;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    long long n,l,r;
    while(cin>>n)
    {
        vec.resize(n);
        for(long long i=0;i<n;i++)
        {
            cin>>vec.at(i).start>>vec.at(i).end;
        }
        sort(vec.begin(),vec.end(),cmp);
        long long result=0;
        for(long long i=0;i<n;i++)
        {
            long long s=vec.at(i).start,e=vec.at(i).end;
            while(i+1<n&&vec[i+1].start<e)
            {
                if(vec.at(i+1).end>e) e=vec.at(i+1).end;
                i++;
            }
            result+=e-s;
        }
        cout<<result<<'\n';
    }
}