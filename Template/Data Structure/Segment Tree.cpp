struct node
{
    int l,r;
    ll sum,lazy;
    void update(ll x)
    {
        sum+=(r-l+1)*x;
        lazy+=x;
    }
}st[500001*4];

struct segment_tree
{
    void pull(int x)
    {
        st[x].sum=st[x<<1].sum+st[x<<1|1].sum;
    }

    void push(int x)
    {
        st[x<<1].update(st[x].lazy),st[x<<1|1].update(st[x].lazy),st[x].lazy=0;
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
            pull(x);
        }
    }

    void modify(int x,int l,int r,ll val)
    {
        int L=st[x].l,R=st[x].r;
        if(L>=l&&R<=r) st[x].update(val);
        else
        {
            push(x);
            int mid=(L+R)>>1;
            if(l<=mid) modify(x<<1,l,r,val);
            if(r>mid) modify(x<<1|1,l,r,val);
            pull(x);
        }
    }

    ll query(int x,int l,int r)
    {
        int L=st[x].l,R=st[x].r;
        if(L>=l&&R<=r) return st[x].sum;
        else
        {
            push(x);
            int mid=(L+R)>>1;
            ll sum=0;
            if(l<=mid) sum+=query(x<<1,l,r);
            if(r>mid) sum+=query(x<<1|1,l,r);
            pull(x);
            return sum;
        }
    }
};
