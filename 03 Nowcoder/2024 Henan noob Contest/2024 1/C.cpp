#include  <bits/stdc++.h>
using namespace std;
#define N 400010
int vt[N],mch[N];
vector<int>g[N];
vector<int>res;
bool dfs(int u,int t)
{
	if(vt[u]==t) return 0;
	vt[u]=t;
	for(auto v:g[u]) 
	if(mch[v]==0||dfs(mch[v],t))
	{
		mch[v]=u;
		return 1;
	}
	return 0;
}
void solve()
{
	int n,k,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>v;
			g[i].push_back(n+v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(dfs(i,i)) ans++;
	if(ans==n) cout<<"Yes\n";
	else 
	{
		cout<<"No\n";
        cout<<n-ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

