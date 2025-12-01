#include <bits/stdc++.h>
using namespace std;
vector<int>g[100010];
int in[100010],ans,n,x,j,indexa,u,fa;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		while(x--)
		{
			cin>>j;
			in[j]++;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) 
	{
		if(in[i]==0) indexa=i;
		break;
	}
	queue<pair<int,int> >q;
	q.push({indexa,0});
	while(!q.empty())
	{
		u=q.front().first;
		fa=q.front().second;
		q.pop();
		for(auto v:g[u])
		{
			if(v==fa) continue;
			q.push({v,u});
		}
		ans=u;
		cout<<ans<<"\n";
	}
	cout<<ans;
} 
