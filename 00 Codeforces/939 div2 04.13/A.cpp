#include <bits/stdc++.h>
using namespace std;
int k,q,a[110],x;
void solve()
{
	cin>>k>>q;
	for(int i=1;i<=k;i++) cin>>a[i];
	while(q--)
	{
		cin>>x;
		for(int i=1;i<=k;i++) 
		x=min(x,a[i]-1);
		cout<<x<<" ";
	}
	cout<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=0;
	cin>>t;
	while(t--) solve();
	
}
