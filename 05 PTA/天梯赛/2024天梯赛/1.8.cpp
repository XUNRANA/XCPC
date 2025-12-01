#include <bits/stdc++.h>
using namespace std;
vector<int>f(10);
int a[10][10];
void solve()
{
	for(int i=1;i<=9;i++) 
	{
		for(int j=1;j<=9;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=1;i<=3;i++) 
	for(int j=1;j<=3;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=1;i<=3;i++) 
	for(int j=4;j<=6;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=1;i<=3;i++) 
	for(int j=7;j<=9;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=4;i<=6;i++) 
	for(int j=1;j<=3;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=4;i<=6;i++) 
	for(int j=4;j<=6;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=4;i<=6;i++) 
	for(int j=7;j<=9;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=7;i<=9;i++) 
	for(int j=1;j<=3;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=7;i<=9;i++) 
	for(int j=4;j<=6;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=9;i++) f[i]=0;
	for(int i=7;i<=9;i++) 
	for(int j=7;j<=9;j++)  f[a[i][j]]=1;
	for(int i=1;i<=9;i++) 
	if(f[i]==0)
	{
		cout<<"0\n";
		return ;
	}
	cout<<"1\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
