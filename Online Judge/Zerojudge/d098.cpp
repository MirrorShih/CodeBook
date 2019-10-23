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
    string s;
    while(getline(cin,s))
    {
        istringstream iss(s);
        string t;
        ll r=0,n;
        while(iss>>t)
        {
            istringstream ss(t);
            ss>>n;
            if(!ss.fail()&&ss.eof()) r+=n;
        }
        cout<<r<<'\n';
    }
}