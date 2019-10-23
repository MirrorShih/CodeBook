#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3;
    bool possible=false;
    cin>>n1>>n2>>n3;
    if(n1>0) n1=1;
    if(n2>0) n2=1;
    if((n1&n2)==n3)
    {
        cout<<"AND"<<endl;
        possible=true;
    }
    if((n1|n2)==n3)
    {
        cout<<"OR"<<endl;
        possible=true;
    }
    if((n1^n2)==n3)
    {
        cout<<"XOR"<<endl;
        possible=true;
    }
    if(!possible) cout<<"IMPOSSIBLE";
}