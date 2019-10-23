#include<iostream>
using namespace std;
int main()
{
	int n,i,j,pass,no_pass;
	bool best=false,worst=false;
	while(cin>>n)
{
pass=-1;
no_pass=-1;
	int array[n];
	for(i=0;i<n;i++)
		cin>>array[i];
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(array[i]>array[j])
			{
				array[i]^=array[j];
				array[j]^=array[i];
				array[i]^=array[j];
			}
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<(i==n-1?"":" ");
		if(array[i]<60)
			no_pass=array[i];
	}
	for(i=n-1;i>=0;i--)
		if(array[i]>=60)
			pass=array[i];
	
	cout<<endl;
	if(no_pass!=-1)
		cout<<no_pass<<endl;
	else
		cout<<"best case"<<endl;
	if(pass!=-1)
		cout<<pass<<endl;
	else
		cout<<"worst case"<<endl;
 } 
}