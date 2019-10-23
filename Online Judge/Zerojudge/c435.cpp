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
    int n,t,tmp=0,r=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        r=max(tmp-t,r);
        tmp=max(tmp,t);
    }
    cout<<r<<'\n';
}