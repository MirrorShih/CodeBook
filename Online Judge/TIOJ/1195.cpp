#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,result=0;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        ll c=count(str.begin()+2,str.end(),str[2]);
        if(c==1||c==3) result+=1000;
        else if(c==4) result+=2000;
        else if(c==2) result+=1500;
    }
    cout<<result<<'\n';
}