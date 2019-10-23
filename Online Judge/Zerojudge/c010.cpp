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
    ll n;
    std::priority_queue<ll> mx;
    std::priority_queue<ll,vector<ll>,greater<ll>> mn;
    cin>>n;
    cout<<n<<'\n';
    mx.emplace(n);
    while(cin>>n)
    {
        if(n>mx.top()) mn.emplace(n);
        else mx.emplace(n);
        if(mx.size()>mn.size()&&mx.size()-mn.size()>1) mn.emplace(mx.top()),mx.pop();
        if(mn.size()>mx.size()) mx.emplace(mn.top()),mn.pop();
        if((mx.size()+mn.size())&1)cout<<mx.top()<<'\n';
        else cout<<(mx.top()+mn.top()>>1)<<'\n';
    }
}