#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int l,r;
    ull sum,lazy;
    void update(ull val)
    {
        sum+=(r-l+1)*val;
        lazy+=val;
    }
} st[500001*4];

void push_up(int x)
{
    st[x].sum=st[x<<1].sum+st[x<<1|1].sum;
}

void push_down(int x)
{
    ull lazy=st[x].lazy;
    st[x<<1].update(lazy),st[x<<1|1].update(lazy);
    st[x].lazy=0;
}

void build(int x,int l,int r)
{
    st[x].l=l,st[x].r=r,st[x].sum=st[x].lazy=0;
    if(l==r) cin>>st[x].sum;
    else
    {
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}

void modify(int x,int l,int r,ull val)
{
    int L=st[x].l,R=st[x].r;
    if(L>=l&&R<=r) st[x].update(val);
    else
    {
        push_down(x);
        int mid=(L+R)>>1;
        if(l<=mid) modify(x<<1,l,r,val);
        if(r>mid) modify(x<<1|1,l,r,val);
        push_up(x);
    }
}

ull query(int x,int l,int r)
{
    int L=st[x].l,R=st[x].r;
    if(L>=l&&R<=r) return st[x].sum;
    else
    {
        push_down(x);
        ull ans=0;
        int mid=(L+R)>>1;
        if(l<=mid) ans+=query(x<<1,l,r);
        if(r>mid) ans+=query(x<<1|1,l,r);
        push_up(x);
        return ans;
    }
}


int main()
{
    AC
    int n,q;
    cin>>n;
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        int v,x,y,k;
        cin>>v;
        if(v==1) cin>>x>>y>>k,modify(1,x,y,k);
        else if(v==2) cin>>x>>y,cout<<query(1,x,y)<<'\n';
    }
}