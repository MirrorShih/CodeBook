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
    vector<bool> isprime(1000001,0);
    vector<int> prime;
    for(int i=2;i<=1000001;i++)
    {
        if(isprime[i]) continue;
        prime.emplace_back(i);
        for(int j=i;j<=1000001;j+=i) isprime[j]=i;
    }
    int n,t;
    while(cin>>n)
    {
        for(auto e:prime)
        {
            if(e>n) break;
            int cnt=0;
            while(n&&!(n%e))
            {
                cnt++;
                n/=e;
            }
            if(cnt>1) cout<<e<<'^'<<cnt;
            else if(cnt==1) cout<<e;
            if(cnt>=1&&n!=1) cout<<" * ";
        }
        cout<<'\n';
    }
}