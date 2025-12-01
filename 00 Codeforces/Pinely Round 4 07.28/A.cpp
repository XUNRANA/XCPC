#include <bits/stdc++.h>
using namespace std;
int n,mx,a[110];
void solve()
{
	mx=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i+=2)
	{
		mx=max(mx,a[i]);
	}
	cout<<mx<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
