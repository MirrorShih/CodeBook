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
    string s1,s2;
    cin>>s1>>s2;
    int n;
    vector<int> v,dp;
    cin>>n;
    unordered_map<char,vector<int>> um;
    for(int i=s2.size()-1;i>=0;i--) um[s2[i]].emplace_back(i);
    for(int i=0;i<s1.size();i++)
    {
        if(um.find(s1[i])==um.end()) continue;
        for(auto e:um[s1[i]]) v.emplace_back(e);
    }
    dp.emplace_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        if(dp.back()<v[i]) dp.emplace_back(v[i]);
        else *lower_bound(dp.begin(),dp.end(),v[i])=v[i];
    }
    if(dp.size()<n) cout<<"sitini na tisa\n";
    else cout<<"kwa nini unaendesha\n";
}