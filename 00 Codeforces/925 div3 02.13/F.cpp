#include <bits/stdc++.h>
using namespace std;
int n,k,p,x,ans;
/*
int in[200010];
vector<int>g[200010];
*/
void solve()
{
	ans=0;
	cin>>n>>k;
	vector<int>in(n+10,0);
	vector<vector<int>>g(n+10,vector<int>());
	//for(int i=1;i<=n;i++) in[i]=0,g[i].clear();
	queue<int>q; 
	while(k--)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(i>=3)
			{
				in[x]++;
				g[p].push_back(x);
			}
			p=x;
		}
	}
	for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
	while(q.size())
	{
		p=q.front();
		q.pop();
		ans++;
		for(auto v:g[p])
		{
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
	if(ans==n) cout<<"YES\n";
	else cout<<"NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
