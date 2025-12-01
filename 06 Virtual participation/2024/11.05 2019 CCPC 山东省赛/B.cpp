#include <bits/stdc++.h>
using namespace std;

vector<int>g[110];
int pre[110];
int suf[110];
int vt[110];
int n,m;
bool bfs(int S)
{
	queue<int>q;
	q.push(S);
	vt[S]=S;
	while(!q.empty())
	{
		int sn=q.front();
		q.pop();
		for(auto v:g[sn]) 
		{
			if(v==S) return 0;
			if(vt[v]==S) continue;
			q.push(v);
			vt[v]=S;
			pre[v]++;
			suf[S]++;
		}
	}
	return true;
}

void solve()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) pre[i]=suf[i]=vt[i]=0,g[i].clear();
	
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	
	for(int i=1;i<=n;i++) 
	if(!bfs(i))
	{
		string ans;
		while(n--) ans+='0';
		cout<<ans<<"\n";
		return ;
	}
	

	string ans;
	for(int i=1;i<=n;i++) 
	if(pre[i]<=n/2&&suf[i]<=n/2) ans+='1';
	else ans+='0';
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
