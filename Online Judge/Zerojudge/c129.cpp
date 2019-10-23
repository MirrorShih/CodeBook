#include<vector>
#include<iostream>
using namespace std;

vector<string> graph;
vector<vector<bool>> visited;
int m,n;

void dfs(int r,int c)
{
    for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
            if(!(r+i<0)&&!(r+i>=m)&&!(c+j<0)&&!(c+j>=n)&&visited.at(r+i).at(c+j)==false&&graph.at(r+i).at(c+j)=='@')
            {
                visited.at(r+i).at(c+j)=true;
                dfs(r+i,j+c);
            }
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    int result=0;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
            break;
        graph.resize(m);
        visited.resize(m,vector<bool>(n));
        for(int i=0;i<m;i++)
            cin>>graph.at(i);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(graph.at(i).at(j)=='@'&&visited.at(i).at(j)==false)
                {
                    result++;
                    dfs(i,j);
                }
        cout<<result<<"\n";
        result=0;
        graph.clear();
        visited.clear();
    }
}