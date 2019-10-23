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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin.ignore();
        if(n<3)
        {
            cout<<"NO\n";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if(n<=45)
        {
            vector<int> v(n);
            for(int i=0;i<n;i++) cin>>v[i];
            sort(v.begin(),v.end());
            bool y=0;
            for(int i=0;i+2<n;i++)
            {
                if(v[i]+v[i+1]>v[i+2])
                {
                    y=1;
                    break;
                }
            }
            if(y) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"YES\n";
        }
    }
}