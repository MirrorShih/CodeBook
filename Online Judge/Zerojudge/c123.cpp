#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    ll n;
    while(cin>>n&&n)
    {
        ll f;
        while(cin>>f&&f)
        {
            queue<ll,list<ll>> q;
            q.push(f);
            stack<ll,list<ll>> s;
            for(ll i=1;i<n;i++)
                cin>>f,q.push(f);
            for(ll i=1;i<=n;i++)
            {
                s.push(i);
                while(s.size()&&s.top()==q.front())
                    s.pop(),q.pop();
            }
            cout<<(s.size()?"No\n":"Yes\n");
        }
        cout<<'\n';
    }
}