#include <bits/stdc++.h>
using namespace std;
int n,t1,s;
void solve()
{
	s=0;
	cin>>n;
	while(n--)
	{
		cin>>t1;
		s+=abs(t1);
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
