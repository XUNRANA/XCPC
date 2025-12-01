priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
for(int i=1;i<=n;i++) dis[i]=(1ll<<31)-1;
dis[s]=0;
q.push({0,s});
while(!q.empty())
{
	int u=q.top().second;
	q.pop();
	if(vt[u]) continue;
	vt[u]=1;
	for(auto v1:g[u])
	{
		int v=v1.first;
		int w=v1.second;
		if(dis[v]>dis[u]+w)
		{
			dis[v]=dis[u]+w;
			q.push({dis[v],v});
		}
	}
}