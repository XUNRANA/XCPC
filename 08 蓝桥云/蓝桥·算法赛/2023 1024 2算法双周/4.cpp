#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int ans,d[100010],f[100010],s[100010],k[100010];
void solve()
{
	int n,p;
	cin>>n>>p;
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i]>>s[i]>>k[i];
		if(f!=0) 
		{
			g[f[i]].push_back(i);
			d[i]++;
		}
	}
	q.push({{k[1],s[1]},1});
	while(!q.empty())
	{
		int dk=q.top().first.first;
		int ds=q.top().first.second;
		int di=q.top().second;
		q.pop();
		if(p>=dk) 
		{
			ans++;
			p+=ds;
			for(auto v:g[di])
			{
				d[v]--;
				if(d[v]==0) q.push({{k[v],s[v]},v});
			}
		}
	} 
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
