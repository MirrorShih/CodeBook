#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

void dfs(int n,int step,string str)
{
    str+=to_string(vec.at(n))+((step==6)?"":" ");
    if(step==6) 
    {
        cout<<str<<"\n";
        return;
    }
    for(int i=1;i<vec.size()-n;i++)
        dfs(n+i,step+1,str);
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    int num;
    bool start=false;
    while(cin>>num)
    {
        if(!num)    break;
        if(start)   cout<<"\n";
        start=1;
        vec.resize(num);
        for(int i=0;i<num;i++)
            cin>>vec.at(i);
        for(int i=0;i<vec.size();i++)
            dfs(i,1,"");
        vec.clear();
    }
}