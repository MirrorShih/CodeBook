#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n;
    while(cin>>n)
    {
        vector<ll> parent,child_num(n),dp(n);
        parent.resize(n,-1);
        queue<ll> q;
        for(ll i=0;i<n;i++)
        {
            ll k;
            cin>>k;
            child_num.at(i)=k;
            for(ll j=0;j<k;j++)
            {
                ll num;
                cin>>num;
                parent.at(num-1)=i;
            }
            if(!k) q.push(i);
        }
        ll root=-1;
        while(!q.empty())
        {
            ll temp=q.front();
            q.pop();
            if(parent.at(temp)==-1)
            {
                root=temp;
                break;
            }
            dp.at(parent.at(temp))=max(dp.at(parent.at(temp)),dp.at(temp)+1);
            child_num.at(parent.at(temp))--;
            if(!child_num.at(parent.at(temp))) q.push(parent.at(temp));
        }
        ll result=0;
        for(auto r:dp)
            result+=r;
        cout<<root+1<<'\n'<<result<<'\n';
    }
}