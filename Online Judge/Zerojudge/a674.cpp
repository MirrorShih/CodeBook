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
    int c,s,q,cnt=1;
    while(cin>>c>>s>>q&&c&&s&&q)
    {
        cout<<"Case #"<<cnt++<<'\n';
        vector<vector<ll>> v(c+1,vector<ll>(c+1,1e9));
        for(int i=0;i<s;i++)
        {
            ll f,t,val;
            cin>>f>>t>>val;
            v[f][t]=val;
            v[t][f]=val;
        }
        for(int k=1;k<=c;k++)
            for(int i=1;i<=c;i++)
                for(int j=1;j<=c;j++)
                    v[i][j]=min(v[i][j],max(v[i][k],v[k][j]));
        for(int i=0;i<q;i++)
        {
            int f,t;
            cin>>f>>t;
            if(v[f][t]==1e9) cout<<"no path\n";
            else cout<<v[f][t]<<'\n';
        }
        cout<<'\n';
    }
}