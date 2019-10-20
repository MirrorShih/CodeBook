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
    int n,m,l=1;
    ll k,t;
    cin>>n>>m>>k;
    deque<pair<ll,int>> mx,mn;
    queue<pair<ll,int>> q;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(i>m) l++;
        while(mx.size()&&i-mx.front().second>=m) mx.pop_front();
        while(mn.size()&&i-mn.front().second>=m) mn.pop_front();
        while(mx.size()&&t>mx.back().first) mx.pop_back();
        while(mn.size()&&t<mn.back().first) mn.pop_back();
        mx.emplace_back(t,i),mn.emplace_back(t,i);
        if(mx.front().first-mn.front().first==k) q.emplace(l,i);
    }
    for(int i=n-m+2;i<n;i++)
    {
        while(mx.size()&&mx.front().second<i) mx.pop_front();
        while(mn.size()&&mn.front().second<i) mn.pop_front();
        if(mx.front().first-mn.front().first==k) q.emplace(i,n);
    }
    cout<<q.size()<<'\n';
    while(q.size())
        cout<<q.front().first<<' '<<q.front().second<<'\n',q.pop();
}