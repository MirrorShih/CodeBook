#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll josephus(ll n,ll m,ll k)
{
    return k>0 ? (josephus(n-1,m,k-1)+m)%n:0;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,m,k;
    while(cin>>n>>m>>k)
    {
        cout<<josephus(n,m,k)+1<<'\n';
    }
}