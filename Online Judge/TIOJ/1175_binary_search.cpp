#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll n;
    cin>>n;
    vector<ll> vec(n);
    vector<ll> dp;
    for(ll i=0;i<n;i++)
        cin>>vec[i];
    dp.push_back(vec[0]);
    for(ll i=1;i<n;i++)
    {
        if(vec[i]>dp.back()) dp.push_back(vec[i]);
        else *lower_bound(dp.begin(),dp.end(),vec[i])=vec[i];
    }
    cout<<dp.size()<<'\n';
}