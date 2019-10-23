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
    int n,t,l;
    cin>>n;
    cin>>l;
    cout<<l<<' ';
    for(int i=1;i<n;i++)
    {
        cin>>t;
        cout<<t-l<<" \n"[i==n-1];
        l=t;
    }
}