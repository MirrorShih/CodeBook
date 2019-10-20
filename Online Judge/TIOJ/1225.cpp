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
    int n,t;
    ll r=0;
    cin>>n;
    stack<int> s;
    while(n--)
    {
        cin>>t;
        while(s.size()&&t>=s.top())
        {
            s.pop();
            if(s.size()) r+=min(t,s.top());
            else r+=t;
        }
        s.emplace(t);
    }
    while(s.size()>1)
    {
        s.pop();
        r+=s.top();
    }
    cout<<r<<'\n';
}