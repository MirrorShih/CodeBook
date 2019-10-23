#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool slove(vector<ll> &vec,ll t)
{
    ll i=0,j=1;
    while(j<vec.size())
    {
        if(vec[j]-vec[i]>t) i++;
        else if(vec[j]-vec[i]<t) j++;
        else if(i==j) j++;
        else return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++)
        cin>>vec[i];
    sort(vec.begin(),vec.end());
    while(q--)
    {
        ll t;
        cin>>t;
        cout<<(slove(vec,t)?"YES\n":"NO\n");
    }
}