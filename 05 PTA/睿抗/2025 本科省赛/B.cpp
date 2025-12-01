#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,s;
	cin>>n>>s;
	int res=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int r,x;
		cin>>r>>x;
		res+=x;
		cnt+=(r==1);
	}
	int ans1=(2*cnt)>=n;
	int ans2=res>=s+50;
	cout<<ans1<<" "<<ans2<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
