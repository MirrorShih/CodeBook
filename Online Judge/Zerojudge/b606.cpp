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
    ll n,t;
    while(cin>>n&&n)
    {
        ll r=0;
        std::priority_queue<int,vector<int>,greater<int>> pq;
        while(n--)
        {
            cin>>t;
            pq.emplace(t);
        }
        while(pq.size()>1)
        {
            t=pq.top();
            pq.pop();
            t+=pq.top();
            pq.pop();
            r+=t,pq.emplace(t);
        }
        cout<<r<<'\n';
    }
}