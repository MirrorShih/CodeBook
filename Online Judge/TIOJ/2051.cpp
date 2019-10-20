#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    string str;
    cin>>str;
    map<string,ll> mp;
    stack<ll> s;
    ll cur=1;
    for(ll i=str.length()-1;i>=0;)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            ll temp=str[i]-'0';
            ll p=10;
            i--;
            while(str[i]>='0'&&str[i]<='9'&&i>=0)
            {
                temp+=((str[i]-'0')*p);
                i--;
                p*=10;
            }
            s.push(temp);
            cur*=temp;
        }
        else if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
        {
            if(str[i+1]<='0'||str[i+1]>'9'&&(i+1<str.size())) s.push(1);
            string temp="";
            temp+=str[i];
            i--;
            while(str[i+1]>='a'&&str[i+1]<='z'&&i>=0)
            {
                temp=str[i]+temp;
                i--;
            }
            mp[temp]+=cur;
            if(s.size()) 
            {
                cur/=s.top();
                s.pop();
            }
        }
        else if(str[i]==')')
        {
            if(str[i+1]<='0'||str[i+1]>'9'&&(i+1<str.size())) s.push(1);
            i--;
        }
        else if(str[i]=='(')
        {
            if(s.size())
            {
                cur/=s.top();
                s.pop();
            }
            i--;
        }
    }
    cout<<str<<'\n';
    for(auto each:mp)
        cout<<each.first<<':'<<each.second<<'\n';
}