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
    cin>>n;
    stack<int> s;
    while(n--)
    {
        int t,num;
        cin>>t;
        if(t==1) s.pop();
        else if(t==2) cout<<s.top()<<'\n';
        else cin>>num,s.emplace(num);
    }
}