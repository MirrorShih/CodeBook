#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    ll num;
    cin>>num;
    while(num--)
    {
        ll n,r=0,p=1;
        cin>>n;
        if(n==1) cout<<"1\n";
        else
        {
            bool b=1;
            while(n!=1&&b)
            {
                for(ll i=9;i>=1;i--)
                {
                    if(i==1) b=0;
                    else if(!(n%i))
                    {
                        n/=i;
                        r+=p*i;
                        p*=10;
                        break;
                    }
                }
            }
            if(b) cout<<r<<'\n';
            else cout<<"-1\n";
        }
    }
}