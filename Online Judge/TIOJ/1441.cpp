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
    int n,t,l=0,r=0;
    cin>>n;
    bool h=1;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(h&&t>l) r++,h^=1;
        else if(!h&&t<l) r++,h^=1;
        l=t;
    }
    cout<<r-h<<'\n';
}