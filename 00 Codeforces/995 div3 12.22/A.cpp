#include <bits/stdc++.h>
using namespace std;
int n,a[110],b[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		if(i+1<=n) x-=b[i+1];
		if(x>0) ans+=x;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
