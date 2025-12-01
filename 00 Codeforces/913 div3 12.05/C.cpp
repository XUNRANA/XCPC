#include <bits/stdc++.h>
using namespace std;
int n,mx;
string s;
int a[27];
void solve()
{
	cin>>n>>s;
	for(int i=0;i<27;i++) a[i]=0;
	for(auto i:s) a[i-'a']++;
	mx=0;
	for(int i=0;i<27;i++) mx=max(mx,a[i]);
	if(n&1)
	{
		if(mx<n-mx) cout<<1<<"\n";
		else cout<<mx-(n-mx)<<"\n";
	} 
	else
	{
		if(mx<=n-mx) cout<<0<<"\n";
		else cout<<mx-(n-mx)<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
