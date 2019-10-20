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
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int r=1e9;
        vector<pair<int,int>> v(n);
        std::priority_queue<int> pq;
        for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            pq.emplace(v[i].second);
            if(pq.size()==k) r=min(r,v[i].first+pq.top()),pq.pop();
        }
        cout<<r<<'\n';
    }
}