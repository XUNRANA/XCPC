#include <bits/stdc++.h>
using namespace std;

int n,a[1010];
void solve()
{
	cin>>n;
	a[1]=2;
	a[2]=0;
	a[3]=1;
	a[4]=9;
	for(int i=5;i<=n;i++)
	{
		int x=a[i-1]+a[i-2]+a[i-3]+a[i-4];
		a[i]=x%10;
	}
	for(int i=1;i<=n;i++) cout<<a[i];
	cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
