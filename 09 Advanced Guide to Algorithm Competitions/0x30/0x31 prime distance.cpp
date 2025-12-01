#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
int main()
{
	int l,r;
	cin>>l>>r;
	vector<int>f(r-l+1);
	for(int i=2;i<=sqrt(r);i++)
	if(is(i)==1) 
	{
		//cout<<i<<endl;
		for(int j=0;j<r-l+1;j++) if(f[j]==0&&(j+l)%i==0) f[j]=1;
	}
	int d=0,pre=-1;
	//for(int i=0;i<r-l+1;i++) cout<<i+l<<" "<<f[i]<<endl;
	for(int i=0;i<r-l+1;i++)
	{
		if(f[i]==0)
		{
		    if(pre==-1) pre=i;
			else d=max(d,i-pre),pre=i; 	
		}  
	}
	cout<<d;
}
