#include <bits/stdc++.h>
using namespace std;
int f,a,b;
void solve()
{
	f=0;
	cin>>a>>b;
	if(a>b) swap(a,b);
	if(a&1 && b&1) f=1;
	else
	{
		if(a==1&&b==2) f=1;
		if(2*a==b&&a&1) f=1;
	}
	
	if(f==1) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
