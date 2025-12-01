#include <bits/stdc++.h>
using namespace std;
vector<int>g[100010];
int n,k,u,v1,idx,ans,v[100010],in[100010];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) v[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v1;
		g[u].push_back(v1);
		g[v1].push_back(u);
		in[v1]++;
		in[u]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++) if(in[i]==1) v[i]=1,q.push(i);
	while(q.size())
	{
		int f=q.front();
		q.pop();
		idx++;
		if(idx>n-k) break;
		ans=max(ans,v[f]);
		for(auto i:g[f])
		{
			v[i]=max(v[i],v[f]+1);
			if(--in[i]==1) q.push(i);
		}
	}
	if(n==k) ans=0;
	cout<<ans<<"\n";
}
