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
        string s="";
        for(int i=n;i;i--)
            s+=i+'0';
        do
        {
            cout<<s<<'\n';
        }while(prev_permutation(s.begin(),s.end()));
    }
}