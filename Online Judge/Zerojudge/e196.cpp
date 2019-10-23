#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> vec(n);
        int result=0;
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            vec.at(temp-1)++;
        }
        for(int i=0;i<n;i++)
            if(vec.at(i)<2) result++;
        cout<<result<<'\n';
    }
}