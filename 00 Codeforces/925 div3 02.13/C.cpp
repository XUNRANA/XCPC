#include <bits/stdc++.h>
using namespace std;
int a[200010],mx,mx1,mx2,n,f1,f2;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]!=a[n])
	{
		mx=1;
		for(int i=2;i<=n;i++) 
		{
			if(a[i]==a[i-1]) mx=max(mx,i);
			else break;
		}
		
		for(int i=n-1;i>=1;i--) 
		{
			if(a[i]==a[i+1]) mx=max(mx,n-i+1);
			else break;
		}
		
	}
	else
	{
		mx1=1;
		for(int i=2;i<=n;i++) 
		{
			if(a[i]==a[i-1]) mx1=max(mx1,i);
			else break;
		}
		
		mx2=1;
		for(int i=n-1;i>=1;i--) 
		{
			if(a[i]==a[i+1]) mx2=max(mx2,n-i+1);
			else break;
		}
		
		if(mx1==n) mx=n;
		else mx=mx1+mx2;
	}
	cout<<n-mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
