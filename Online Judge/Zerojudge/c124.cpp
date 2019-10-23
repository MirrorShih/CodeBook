#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<string>> vec;
vector<vector<vector<int>>> Distance;
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int L,R,C;

struct point
{
    int x,y,z;
};

int bfs(point p)
{
    queue<point> q;
    q.push(p);
    vec.at(p.x).at(p.y).at(p.z)='#';
    Distance.at(p.x).at(p.y).at(p.z)=0;
    while(!q.empty())
    {
        point current=q.front();
        q.pop();
        for(int i=0;i<6;i++)
        {
            point next;
            next.x=current.x+dir[i][0];
            next.y=current.y+dir[i][1];
            next.z=current.z+dir[i][2];
            if(next.x<0||next.x>=L||next.y<0||next.y>=R||next.z<0||next.z>=C)   continue;
            if(vec.at(next.x).at(next.y).at(next.z)!='#')
            {
                q.push(next);
                Distance.at(next.x).at(next.y).at(next.z)=Distance.at(current.x).at(current.y).at(current.z)+1;
                if(vec.at(next.x).at(next.y).at(next.z)=='E')
                    return Distance.at(next.x).at(next.y).at(next.z);
                vec.at(next.x).at(next.y).at(next.z)='#';
            }
        }
    }
    return -1;
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>L>>R>>C)
    {
        if(!L&&!R&&!C)  break;
        point p;
        vec.resize(L,vector<string>(R));
        Distance.resize(L,vector<vector<int>>(R,vector<int>(C)));
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                cin>>vec.at(i).at(j);
                for(int k=0;k<C;k++)
                    if(vec.at(i).at(j).at(k)=='S')   p.x=i,p.y=j,p.z=k;
            }
        }
        int result=bfs(p);
        if(result!=-1) cout<<"Escaped in "<<result<<" minute(s)."<<"\n";
        else cout<<"Trapped!"<<"\n";
        vec.clear();
        Distance.clear();
    }
}