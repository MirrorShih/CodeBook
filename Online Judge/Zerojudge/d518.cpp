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
    int n;
    while(cin>>n)
    {
        unordered_map<string,int> um;
        int cnt=1;
        while(n--)
        {
            string s;
            cin>>s;
            if(um.find(s)==um.end()) cout<<"New! "<<cnt<<'\n',um[s]=cnt++;
            else cout<<"Old! "<<um[s]<<'\n';
        }
    }
}