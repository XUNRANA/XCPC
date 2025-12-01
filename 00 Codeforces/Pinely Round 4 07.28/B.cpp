#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
void solve()
{
	
	cin>>n;
	
	for(int i=1;i<=n;i++) a[i]=b[i]=0;
	
	for(int i=1;i<=n-1;i++) cin>>b[i];

	for(int i=1;i<=n;i++)
	{
		a[i]|=b[i];
		a[i]|=b[i-1];
	}
	
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]!=(a[i]&a[i+1]))
		{
			cout<<"-1\n";
			return ;
		}
	}
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";

	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
