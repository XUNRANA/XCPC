#include <bits/stdc++.h>
using namespace std;
void fx(int x)
{
	if(x==0) cout<<"2(0)";
	else if(x==1) cout<<"2";
	else if(x==2) cout<<"2(2)";
	else
	{
		int f=0;
		cout<<"2(";
		for(int i=31;i>=0;i--) 
		if(x>>i&1) 
		{
			if(f==1) cout<<"+";
			fx(i);
			f=1;
		}
		cout<<")";
	}
}
int main()
{
	int n;
	cin>>n;
	int f=0;
	for(int i=31;i>=0;i--) 
	if(n>>i&1) 
	{
		if(f==1) cout<<"+";
		fx(i);
		f=1;
	}
}
