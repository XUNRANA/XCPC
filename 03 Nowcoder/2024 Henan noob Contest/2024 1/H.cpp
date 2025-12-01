#include <bits/stdc++.h>
using namespace std;
long long n,s,mx,a[200010];
void solve()
{
	s=mx=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s+=a[i];
		mx=max(mx,a[i]);
	}
	cout<<s+max(n,mx*(n-1))<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
