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
    unsigned long long a,b;
    while(cin>>a>>b)
        cout<<(-((unsigned long long)pow(2,(unsigned long long)log2(a^b)+1))&min(a,b))<<'\n';
}