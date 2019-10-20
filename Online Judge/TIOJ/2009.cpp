#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    AC
    int n,k,r=0;
    cin>>n>>k;
    vector<int> dis(n);
    for(int i=0;i<n;i++)
        cin>>dis[i];
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        dis[i]=t-dis[i];
        if(dis[i]<0) dis[i]+=9;
    }
    for(int i=0;i<=n-k;i++)
    {
        if(dis[i])
        {
            int t=dis[i];
            for(int j=0;j<k;j++)
            {
                dis[i+j]-=t;
                if(dis[i+j]<0) dis[i+j]+=9;
            }
            r+=t;
        }
    }
    if(count(dis.begin(),dis.end(),0)==n) cout<<r<<'\n';
    else cout<<0<<'\n';
}