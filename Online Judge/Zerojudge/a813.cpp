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
    cin>>n>>t;
    stack<int> s;
    unordered_map<int,int> m;
    s.emplace(t);
    m[t]++;
    for(int i=1;i<n;i++)
    {
        cin>>t;
        while(s.size()&&t>s.top())
        {
            r+=m[s.top()];
            m[s.top()]=0;
            s.pop();
        }
        if(s.size()&&t==s.top()) r+=m[t];
        else s.emplace(t);
        m[t]++;
        if(s.size()>1) r++;
    }
    cout<<r*2<<'\n';
}