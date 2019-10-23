#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> all,vec(8,vector<int>(8));
vector<bool> c(8),lr(15),rl(15);


void dfs(int r,vector<int> temp)
{
    if(r==8)
    {
        all.push_back(temp);
        return;
    }
    for(int i=0;i<8;i++)
    {
        int x1=r-i+7,x2=r+i;
        if(!lr.at(x1)&&!rl.at(x2)&&!c.at(i))
            {
                lr.at(x1)=true;
                rl.at(x2)=true;
                c.at(i)=true;
                temp.push_back(i);
                dfs(r+1,temp);
                lr.at(x1)=false;
                rl.at(x2)=false;
                c.at(i)=false;
                temp.erase(temp.end()-1);
            }
    }
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    int k,sum=0;
    cin>>k;
    vector<int> temp;
    dfs(0,temp);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<8;j++)
            for(int a=0;a<8;a++)
                cin>>vec.at(j).at(a);
        for(auto v:all)
        {
            int t=0;
            for(int j=0;j<8;j++)
            {
                t+=vec.at(j).at(v.at(j));
            }
            sum=max(sum,t);
        }
        cout<<sum<<"\n";
sum=0;
    }
}