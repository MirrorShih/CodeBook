struct DSU
{
    vector<int> v;

    DSU(int n)
    {
        for(int i=0;i<n;i++) v.emplace_back(i);
    }

    int Find(int x)
    {
        if(v[x]==x) return x;
        return v[x]=Find(v[x]);
    }

    void Union(int x,int y)
    {
        v[Find(x)]=Find(y);
    }
};