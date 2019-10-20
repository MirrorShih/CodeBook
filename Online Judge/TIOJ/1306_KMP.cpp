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
    int n,num;
    string p,t;
    cin>>n;
    while(n--)
    {
        cin>>t>>num;
        while(num--)
        {
            ll r=0;
            cin>>p;
            vector<int> f(p.size()+1);
            f[0]=-1;
            for(int i=1,j=-1;p[i];f[i++]=j)
            {
                while(~j&&p[i]!=p[j+1]) j=f[j];
                if(p[i]==p[j+1]) j++;
            }
            for(int i=0,j=-1;t[i];i++)
            {
                while(~j&&t[i]!=p[j+1]) j=f[j];
                if(t[i]==p[j+1]) j++;
                if(j==p.size()-1) r++;
            }
            cout<<r<<'\n';
        }
    }
}