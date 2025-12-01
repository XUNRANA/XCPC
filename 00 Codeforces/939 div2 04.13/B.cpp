#include <bits/stdc++.h>
using namespace std;
int ans,n,t;
void solve()
{
	ans=0;
	cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		m[t]++;
	}
	for(int i=1;i<=n;i++) if(m[i]==2) ans++;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=0;
	cin>>t1;
	while(t1--) solve();
	
}
