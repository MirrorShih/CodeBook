struct BIT
{
    vector<int> v;
    BIT(int n)
    {
        v.resize(n);
    }
    int query(int x)
    {
        int r=0;
        for(;x;x-=lowbit(x))
            r=max(r,v[x]);
        return r;
    }
    void modify(int x,int val)
    {
        for(;x<v.size();x+=lowbit(x))
            v[x]=max(v[x],val);
    }
};