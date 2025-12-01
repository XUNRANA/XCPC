#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,d;
void solve()
{
	cin>>n>>k;
	if(k==n)
	{
		cout<<"YES\n";
		cout<<"1\n1\n";
	}
	else if(k>n) cout<<"NO\n";
	else 
	{
		if(n-(k-1)>k-1)
		{
			cout<<"YES\n";
			cout<<"2\n";
			cout<<n-(k-1)<<" "<<1<<"\n";
		}
		else cout<<"NO\n";
	} 
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
