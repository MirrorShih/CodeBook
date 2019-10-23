#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct box
{
    ll w,f;
};

vector<box> vec;

bool cmp(box a,box b)
{
    return a.w*b.f<b.w*a.f;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n;
    while(cin>>n)
    {
        ll result=0,temp=0;
        vec.resize(n);
        for(ll i=0;i<n;i++)
            cin>>vec[i].w;
        for(ll i=0;i<n;i++)
            cin>>vec[i].f;
        sort(vec.begin(),vec.end(),cmp);
        for(ll i=0;i<n;i++)
        {
            result+=vec[i].f*temp;
            temp+=vec[i].w;
        }
        cout<<result<<'\n';
        vec.clear();
    }
}