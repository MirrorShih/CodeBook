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
    string s,t;
    cin>>s>>t;
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1));
    vector<vector<int>> v(s.size()+1,vector<int>(t.size()+1));
    for(int i=1;i<=s.size();i++)
        for(int j=1;j<=t.size();j++)
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1,v[i][j]=1;
            else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j],v[i][j]=2;
            else dp[i][j]=dp[i][j-1],v[i][j]=3;
    int x=s.size(),y=t.size();
    stack<char> r;
    while(x&&y)
    {
        if(v[x][y]==1) r.emplace(s[x-1]),x--,y--;
        else if(v[x][y]==2) x--;
        else y--;
    }
    while(r.size()) cout<<r.top(),r.pop();
    cout<<'\n';
}
