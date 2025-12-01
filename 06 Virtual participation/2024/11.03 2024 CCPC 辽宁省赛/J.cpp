#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,x[1010],y[1010];
void solve()
{
	cin>>n;
	cin>>a>>b>>c;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i]; 
	
	cin>>d;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]+y[i]>=c) continue;
		x[i]=min(a,x[i]+d);
		if(x[i]+y[i]>=c) ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
