#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    string str;
    ll n1,n2;
    while(getline(cin,str))
    {
        
        stack<ll,list<ll>> s;
        string t;
        istringstream iss(str);
        while(iss>>t)
        {
            if(t=="+") n2=s.top(),s.pop(),n1=s.top(),s.pop(),s.push(n1+n2);
            else if(t=="-") n2=s.top(),s.pop(),n1=s.top(),s.pop(),s.push(n1-n2);
            else if(t=="*") n2=s.top(),s.pop(),n1=s.top(),s.pop(),s.push(n1*n2);
            else if(t=="/") n2=s.top(),s.pop(),n1=s.top(),s.pop(),s.push(n1/n2);
            else if(t=="%") n2=s.top(),s.pop(),n1=s.top(),s.pop(),s.push(n1%n2);
            else s.push(stoll(t));
        }
        cout<<s.top()<<'\n';
    }
}