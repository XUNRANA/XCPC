#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(b<=a) cout<<n*a<<"\n";
	else
	{
		if(b-n+1>=a) cout<<(b-n+1+b)*n/2<<"\n";
		else cout<<(a+b)*(b-a+1)/2+(n-(b-a+1))*a<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
