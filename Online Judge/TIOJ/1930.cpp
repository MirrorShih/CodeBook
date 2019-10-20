#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

int main()
{
    //AC
    int t,n,m,a;
    input(t);
    while(t--)
    {
        input(n),input(m),input(a);
        ll r=0;
        list<int> l;
        vector<list<int>::iterator> v(n+1);
        vector<int> ans;
        list<int>::iterator it;
        l.emplace_back(a);
        v[a]=l.begin();
        for(int i=0;i<m;i++)
        {
            int k,b,c;
            input(k),input(a),input(b),input(c);
            if(k==1)
            {
                if(c==1) v[a]=l.insert(v[b],a);
                else it=v[b],v[a]=l.insert(++it,a);
            }
            else if(k==2) it=v[b],l.splice(v[c],l,v[a],++it);
            else
            {
                bool flag=1;
                it=v[a];
                auto tmp=it;
                if(c==1)
                {
                    while(b--)
                    {
                        ans.emplace_back(*it);
                        if(it==l.begin())
                        {
                            r+=b;
                            flag=0;
                            break;
                        }
                        it--;
                    }
                    if(flag) it++;
                    l.erase(it,++tmp);
                }
                else
                {
                    while(b--)
                    {
                        if(it==l.end())
                        {
                            r+=b+1;
                            break;
                        }
                        ans.emplace_back(*it);
                        it++;
                    }
                    l.erase(tmp,it);
                }
            }
        }
        cout<<r<<'\n';
        for(auto e:ans)
            cout<<e<<'\n';
    }
}