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
    int n,m,t;
    cin>>n>>m;
    vector<bool> v(n+1+1,1);
    v[n+1]=0;
    for(int i=0;i<m;i++)
    {
        cin>>t;
        if(!v[t]) cout<<"0u0 ...... ?\n";
        else
        {
            for(int j=t+1;j<=n+1;j++)
            {
                if(v[j])
                {
                    cout<<j<<'\n';
                    v[j]=0;
                    break;
                }
                if(j==n+1) cout<<"0u0 ...... ?\n";
            }
        }
    }
}