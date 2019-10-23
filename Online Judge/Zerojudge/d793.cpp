#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int c;
    vector<pair<int,int>> child;
};

int main()
{
    AC
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<node>> v(n+1,vector<node>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>v[i][j].c;
                if(j>1) v[i][j].child.emplace_back(i,j-1),v[i][j-1].child.emplace_back(i,j);
                if(i>1) v[i][j].child.emplace_back(i-1,j),v[i-1][j].child.emplace_back(i,j);
            }
        }
        vector<vector<int>> dis(n+1,vector<int>(m+1,1e9));
        std::priority_queue<tuple<int,int,int>> pq;
        dis[1][1]=v[1][1].c;
        pq.emplace(-dis[1][1],1,1);
        while(pq.size())
        {
            int x,y,c;
            tie(c,x,y)=pq.top();
            if(x==n&&y==m) break;
            pq.pop();
            for(auto e:v[x][y].child)
            {
                int x2,y2;
                tie(x2,y2)=e;
                if(dis[x2][y2]>dis[x][y]+v[x2][y2].c)
                {
                    dis[x2][y2]=dis[x][y]+v[x2][y2].c;
                    pq.emplace(-dis[x2][y2],x2,y2);
                }
            }
        }
        cout<<dis[n][m]<<'\n';
    }
}