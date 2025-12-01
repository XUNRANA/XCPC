#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,t;
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mx=max(mx,t); 
	}
	cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
