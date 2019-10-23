#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<int> vec;

int Find(int x)
{
    if(vec.at(x)==x)    return x;
    return vec.at(x)=Find(vec.at(x));
}

void Union(int x,int y)
{
    int X=Find(x),Y=Find(y);
    vec.at(X)=Y;
}

int main()
{
ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            vec.push_back(i);
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            Union(i,temp);
        }
        list<int> li;
        for(int i=0;i<n;i++)
            li.push_back(Find(i));
        li.sort();
        li.unique();
        cout<<li.size()<<endl;
        li.clear();
        vec.clear();
    }
}