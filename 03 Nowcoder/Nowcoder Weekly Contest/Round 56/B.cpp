#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t;
void solve()
{
	s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s+=t;
	}
	cout<<min(s/k,m)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

