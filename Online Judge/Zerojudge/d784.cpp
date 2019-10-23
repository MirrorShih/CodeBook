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
    int t,n;
    cin>>t;
    while(t--)
    {
        int r,s,tmp;
        cin>>n;
        cin>>tmp;
        r=s=tmp;
        for(int i=1;i<n;i++)
        {
            cin>>tmp;
            if(s>=0) s+=tmp;
            if(s<0) s=tmp;
            r=max(r,s);
        }
        cout<<r<<'\n';
    }
}