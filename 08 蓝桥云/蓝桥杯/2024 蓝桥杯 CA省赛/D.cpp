#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,ans,a[200010],b[200010];
vector<int>ga[200010];
vector<int>gb[200010];
/*
2 2 
10 20
10 30
1 2
2 1
*/
/*
5 4
10 20 30 40 50 
10 40 20 30
1 2 
1 3 
2 4
3 5
1 2
1 3 
3 4

*/
void dfs(int au,int fa,int bu,int fb,int l)
{
	map<int,int>m;
	for(auto v:ga[au])
	{
		if(v==fa) continue;
		else m[a[v]]=v;
	}
	
	for(auto v:gb[bu])
	{
		if(v==fb) continue;
		else 
		{
			if(m.count(b[v])) 
			{
				dfs(m[b[v]],au,v,bu,l+1);
			}
		}
	}
	
	//cout<<au<<" "<<fa<<" "<<bu<<" "<<fb<<" "<<l<<"\n";
	//cout<<l<<"\n";
	ans=max(ans,l);
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<n;i++) 
	{
		cin>>u>>v;
		ga[u].push_back(v);
		ga[v].push_back(u);
	}
	
	for(int i=1;i<m;i++) 
	{
		cin>>u>>v;
		gb[u].push_back(v);
		gb[v].push_back(u);
	}
	if(a[1]!=b[1]) cout<<"0";
	else
	{
		dfs(1,0,1,0,1);
		cout<<ans;
	}
	return 0;
}
