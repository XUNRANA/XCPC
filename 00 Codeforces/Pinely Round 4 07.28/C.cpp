#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
void solve()
{
	cin>>n;
	int c1=0,c2=0,mi=1e9,mx=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]&1) c1=1;
		else c2=1;
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
	}
	if(!c1||!c2)
	{
		int d=mx-mi;
		vector<int>ans;
		while(d!=0)
		{
			int t=mx+mi>>1;
			ans.push_back(t);
			mi=1e9,mx=0;
			for(int i=1;i<=n;i++)
			{
				a[i]=abs(a[i]-t);
				mi=min(mi,a[i]);
				mx=max(mx,a[i]);
			}
			d=mx-mi;
		}
		if(mx!=0) ans.push_back(mx);
		cout<<ans.size()<<"\n";
		for(auto i:ans) cout<<i<<" ";
		cout<<"\n";
	}
	else cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
