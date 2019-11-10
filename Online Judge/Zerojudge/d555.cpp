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
    int n,c=1;
    while(cin>>n)
    {
        deque<pair<int, int>> dq;
        vector<pair<int,int>> v(n);
        for(auto &e:v) cin>>e.first,cin>>e.second;
        sort(v.begin(),v.end());
        dq.emplace_back(v[0]);
        for(int i=1;i<n;i++)
        {
            while(dq.size()&&v[i].first>=dq.back().first && v[i].second>=dq.back().second) dq.pop_back();
            dq.emplace_back(v[i]);
        }
        cout<<"Case "<<c++<<":\nDominate Point: "<<dq.size()<<'\n';
        while(dq.size()) cout<<'('<<dq.front().first<<','<<dq.front().second<<")\n",dq.pop_front();
    }
}
