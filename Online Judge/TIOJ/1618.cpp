#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,k,p;
    ll r=0,t=0;;
    cin>>n>>k;
    vector<pair<int,int>> v(n+1);
    deque<int> dq;
    for(int i=1;i<=n;i++)
        cin>>v[i].first;
    for(int i=1;i<=n;i++)
        cin>>v[i].second;
    for(int i=1;i<=n;i++)
    {
        t+=v[i].second;
        while(dq.size()&&v[dq.back()].first<=v[i].first) t-=v[dq.back()].second,dq.pop_back();
        dq.emplace_back(i);
        while(dq.front()<i-k+1) t-=v[dq.front()].second,dq.pop_front();
        if(t>r) p=i,r=t;
    }
    cout<<p<<' '<<r<<'\n';
}