#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct Node
{
    long parent=-1;
    long num=0;
    vector<long> child{};
};

vector<Node> vec;
long result=0;

long dfs(long i)
{
    if(!vec.at(i).num) return 0;
    else if(vec.at(i).num==1) return dfs(vec.at(i).child.at(0))+1;
    else
    {
        priority_queue<long> pq;
        for(long j=0;j<vec.at(i).child.size();j++)
            pq.push(dfs(vec.at(i).child.at(j))+1);
        long temp=pq.top();
        pq.pop();
        result=max(result,temp+pq.top());
        return temp;
    }
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    long n;
    while(cin>>n)
    {
        vec.resize(n);
        for(long i=0;i<n-1;i++)
        {
            long parent,child;
            cin>>parent>>child;
            vec.at(parent).num++;
            vec.at(parent).child.push_back(child);
            vec.at(child).parent=parent;
        }
        for(long i=0;i<n;i++)
        {
            if(vec.at(i).parent==-1)
            {
                result=max(dfs(i),result);
                break;
            }
        }
        cout<<result<<"\n";
        result=0;
        vec.clear();
    }
}