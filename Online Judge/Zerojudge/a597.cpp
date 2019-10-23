#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
vector<string> v;
int mx,r,m,n;

int dfs(int x,int y)
{
    bool f=1;
    int t=1;
    v[x][y]='X';
    for(int i=0;i<4;i++)
        if(x+dir[i][0]<=m&&x+dir[i][0]>0&&y+dir[i][1]<n&&y+dir[i][1]>=0&&v[x+dir[i][0]][y+dir[i][1]]=='J') f=0,t+=dfs(x+dir[i][0],y+dir[i][1]);
    if(f) return 1;
    return t;
}

int main()
{
    AC
    while(cin>>m>>n)
    {
        mx=r=0;
        v.clear();
        v.resize(m+1);
        for(int i=1;i<=m;i++) cin>>v[i];
        for(int i=1;i<=m;i++)
            for(int j=0;j<n;j++)
                if(v[i][j]=='J') mx=max(mx,dfs(i,j)),r++;
        cout<<r<<' '<<mx<<'\n';
    }
}