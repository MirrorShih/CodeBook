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
    cin>>n>>t;
    vector<int> r(n,0);
    stack<pair<int,int>> s;
    s.emplace(t,0);
    for(int i=1;i<n;i++)
    {
        cin>>t;
        while(s.size()&&t>=s.top().first)
        {
            r[s.top().second]=i-s.top().second;
            s.pop();
        }
        s.emplace(t,i);
    }
    s.pop();
    while(s.size())
    {
        r[s.top().second]=n-s.top().second-1;
        s.pop();
    }
    for(auto e:r)
        cout<<e<<'\n';
}