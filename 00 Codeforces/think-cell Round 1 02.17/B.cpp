#include <bits/stdc++.h>
using namespace std;
int n,l,r; 
void solve()
{
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		if(i&1) cout<<l++<<" ";
		else cout<<r--<<" ";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
