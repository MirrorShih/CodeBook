#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int l,r;
    ll sum;
    bool lazy;
    void update()
    {
        sum=sqrt(sum);
    }
} st[300000*4+1];

void push_up(int x)
{
    st[x].sum=st[x<<1].sum+st[x<<1|1].sum;
    st[x].lazy=st[x<<1].lazy&st[x<<1|1].lazy;
}

void build(int x,int l,int r)
{
    st[x].l=l,st[x].r=r,st[x].sum=0,st[x].lazy=0;
    if(l==r) 
    {
        cin>>st[x].sum;
        if(st[x].sum==1) st[x].lazy=1;
    }
    else
    {
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}

void modify(int x,int l,int r)
{
    if(st[x].lazy==1) return;
    int L=st[x].l,R=st[x].r;
    if(L==R) 
    {
        st[x].update();
        if(st[x].sum==1) st[x].lazy=1;
    }
    else
    {
        int mid=(L+R)>>1;
        if(l<=mid) modify(x<<1,l,r);
        if(r>mid) modify(x<<1|1,l,r);
        push_up(x);
    }
}

ll query(int x,int l,int r)
{
    int L=st[x].l,R=st[x].r;
    if(L>=l&&R<=r) return st[x].sum;
    else
    {
        int mid=(L+R)>>1;
        ll ans=0;
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
    cin>>n>>q;
    build(1,1,n);
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t) modify(1,l,r);
        else cout<<query(1,l,r)<<'\n';
    }
}