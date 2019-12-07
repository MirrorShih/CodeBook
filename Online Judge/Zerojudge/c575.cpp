#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int n,k;
vector<int> v;

bool slove(int x)
{
    int cur=v[0]+x,cnt=1;
    for(int i=1;cnt<k&&i<n;i++)
        if(v[i]>cur) cnt++,cur=v[i]+x;
    if(cur>=v[n-1]) return 1;
    return 0;
}

int main()
{
    AC
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int l = 1,r=v[n-1]-v[0],ans;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if(slove(m)) ans=m,r=m-1;
        else l=m+1;
    }
    cout<<ans<<'\n';
}
