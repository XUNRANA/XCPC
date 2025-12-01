#include <bits/stdc++.h>
using namespace std;
long long n,t,s,mi=1e18;
void solve()
{
	cin>>n;
	while(n--)
	{
		cin>>t;
		s+=t;
		mi=min(s,mi);
	}
	if(mi<=0) cout<<s-mi;
	else cout<<s;
} 

int main()
{
	int t;
	t=1;
	//cin>>t;
	while(t--) solve();
}
