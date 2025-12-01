#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long

vector<int>g[N];
int n,p,k,v,a[N],b[N],in[N];
void solve()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) 
		{
			cin>>v;
			g[v].push_back(i);
			in[i]++;
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++) if(!in[i]) q.push({a[i],i});
	vector<int>ans;
	while(!q.empty())
	{
		int u=q.top().second;
		if(p>=a[u]) p+=b[u];
		else break;
		ans.push_back(u);
		q.pop();
		for(auto v:g[u])
		{
			in[v]--;
			if(!in[v]) q.push({a[v],v});
		}
	}
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
