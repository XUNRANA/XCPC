#include <bits/stdc++.h>
using namespace std;
int n,in[60];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) in[i]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		in[u]++;
		in[v]++;
	}
	if(n==2)
	{
		cout<<"Bob\n";
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(in[i]==1) cnt++;
	int t=n-1-cnt;
	if(t&1) cout<<"Alice\n";
	else cout<<"Bob\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
