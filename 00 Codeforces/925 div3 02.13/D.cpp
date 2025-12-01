#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,x1,y1,n,ans,a[200010],b[200010],c[200010];
void solve()
{
	ans=0;
	map<pair<int,int>,int>m;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{
		x1=a[i]%x;
		y1=a[i]%y;
		//cout<<x1<<" "<<y1<<"\n";
		if(m[make_pair(x-x1,y1-y)]!=0) ans+=m[make_pair(x-x1,y1-y)];
		if(m[make_pair(x-x1,y1)]!=0) ans+=m[make_pair(x-x1,y1)];
		if(m[make_pair(-x1,y1-y)]!=0) ans+=m[make_pair(-x1,y1-y)];
		if(m[make_pair(-x1,y1)]!=0) ans+=m[make_pair(-x1,y1)];
		m[make_pair(x1,y1)]++;
	}
	//for(auto i:m) cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
