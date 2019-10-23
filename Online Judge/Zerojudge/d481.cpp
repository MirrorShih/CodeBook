#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll m,n1,n2,p;
    while(cin>>m>>n1>>n2>>p)
    {
        if(n1!=n2) 
        {
            cout<<"Error\n";
            continue;
        }
        vector<vector<ll>> matrix1(m,vector<ll>(n1)),matrix2(n2,vector<ll>(p));
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n1;j++)
                cin>>matrix1[i][j];
        for(ll i=0;i<n2;i++)
            for(ll j=0;j<p;j++)
                cin>>matrix2[i][j];
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<p;j++)
            {
                ll result=0;
                for(ll k=0;k<n1;k++)
                {
                    result+=matrix1[i][k]*matrix2[k][j];
                }
                cout<<result<<' ';
            }
            cout<<'\n';
        }
    }
}