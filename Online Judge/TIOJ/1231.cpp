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
    int n,a,b,k,p=0,r=0;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    cin>>k;
    sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
    std::priority_queue<int> pq;
    for(int i=k;i;i--)
    {
        while(p<v.size()&&v[p].second>=i) pq.emplace(v[p++].first);
        if(pq.empty()) r--;
        else r+=pq.top(),pq.pop();
    }
    cout<<r<<'\n';
}