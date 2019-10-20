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
    int q,n,x;
    cin>>q;
    std::priority_queue<int> mx;
    std::priority_queue<int,vector<int>,greater<int>> mn;
    cin>>n>>x;
    mx.emplace(x);
    while(--q)
    {
        cin>>n;
        if(n==1)
        {
            cin>>x;
            if(x>mx.top()) mn.emplace(x);
            else mx.emplace(x);
            if(mx.size()>mn.size()&&mx.size()-mn.size()>1) mn.emplace(mx.top()),mx.pop();
            if(mn.size()>mx.size()) mx.emplace(mn.top()),mn.pop();
        }
        else cout<<mx.top()<<'\n';
    }
}