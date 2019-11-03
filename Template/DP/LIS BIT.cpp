for(int i=0;i<n;i++)
{
    int temp=sum.query(v[i]-1)+1;
    r=max(r,temp);
    sum.modify(v[i],temp);
}