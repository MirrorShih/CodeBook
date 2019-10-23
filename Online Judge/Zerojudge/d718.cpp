#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,m,t,cnt=1;
    while(cin>>n)
    {
        cout<<"Line #"<<cnt++<<'\n';
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
        {
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>t;
                um[t]=i;
            }
        }
        string s;
        list<int> l;
        vector<int> v(n+1,0);
        vector<list<int>::iterator> it(n+1);
        list<int>::iterator tit;
        while(cin>>s)
        {
            if(s=="ENQUEUE")
            {
                cin>>t;
                if(um.find(t)==um.end()) l.emplace_back(t);
                else if(!v[um[t]]) l.emplace_back(t),v[um[t]]++,it[um[t]]=--l.end();
                else tit=it[um[t]],it[um[t]]=l.insert(++tit,t),v[um[t]]++;
            }
            else if(s=="DEQUEUE") 
            {
                if(um.find(l.front())!=um.end()) v[um[l.front()]]--;
                cout<<l.front()<<'\n',l.pop_front();
            }
            else break;
        }
    }
}