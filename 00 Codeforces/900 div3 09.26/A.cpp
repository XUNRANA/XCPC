#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,t,f=0;
	cin>>n>>k;
	while(n--)
	{
		cin>>t;
		if(t==k) f=1;
	}
	if(f==1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
