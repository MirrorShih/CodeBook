#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    ll n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        ll p=0,q=0,l=s.size();
        for(ll i=0;i<l;i++)
        {
            if(s[i]=='p') p++;
            else if(s[i]=='q'&&p>q) q++;
        }
        cout<<q<<'\n';
    }
}