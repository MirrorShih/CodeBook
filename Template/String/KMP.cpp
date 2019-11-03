for(int i=1,j=-1;p[i];f[i++]=j)
{
    while(~j&&p[i]!=p[j+1]) j=f[j];
    if(p[i]==p[j+1]) j++;
}
for(int i=0,j=-1;t[i];i++)
{
    while(~j&&t[i]!=p[j+1]) j=f[j];
    if(t[i]==p[j+1]) j++;
    if(j==p.size()-1) //成功
}