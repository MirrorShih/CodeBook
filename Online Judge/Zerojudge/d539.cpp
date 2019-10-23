#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int l,r,max;
} st[500001*4];

void push_up(int x)
{
    st[x].max=max(st[x<<1].max,st[x<<1|1].max);
}

void build(int x,int l,int r)
{
    st[x].l=l,st[x].r=r,st[x].max=0;
    if(l==r) cin>>st[x].max;
    else
    {
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}

int query(int x,int l,int r)
{
    int L=st[x].l,R=st[x].r;
    if(L>=l&&R<=r) return st[x].max;
    else
    {
        int mid=(L+R)>>1,ans=0;
        if(l<=mid) ans=query(x<<1,l,r);
        if(r>mid) ans=max(ans,query(x<<1|1,l,r));
        return ans;
    }
    
}

int main()
{
    AC
    int n,m;
    cin>>n;
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<query(1,min(a,b),max(a,b))<<'\n';
    }
}