#include <bits/stdc++.h>
using namespace std;
int n,a[510],x[510],mx,in;
void solve()
{
	cin>>n;
	mx=0;
	for(int i=2;i<=n;i++) 
	{
		cin>>x[i];
		if(x[i]>=mx)
		{
			mx=x[i];
			in=i;
		}
	}
	if(mx==1)
	{
		for(int i=1;i<=n;i++) cout<<i+1<<" ";
	    cout<<"\n";
	    return ;
	}
	a[in]=mx;
	for(int i=in+1;i<=n;i++) a[i]=a[i-1]+x[i];
	a[in-1]=1e9;
	for(int i=in-2;i>=1;i--) a[i]=a[i+1]-x[i+1];
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
