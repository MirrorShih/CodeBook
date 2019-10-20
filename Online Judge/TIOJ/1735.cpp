#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    while(cin>>n)
    {
        string str;
        ll r=0,t=0;
        cin>>str;
        for(ll i=0;i+n<str.size();i++)
        {
            if(str[i]==str[i+n]) t++;
            else t=0;
            if(t>=n) r++;
        }
        cout<<r<<'\n';   
    }
}