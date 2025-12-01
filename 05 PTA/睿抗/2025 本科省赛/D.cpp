#include <bits/stdc++.h>
using namespace std;
int n,m;
int d[11][11];
int c[11][11];
void solve()
{
	cin>>n>>m;
	if(!m)
	{
		cout<<"1 0\n";
		return ;
	}
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n;j++) d[i][j]=c[i][j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		d[u][v]=d[v][u]=1;
		if(u>v) swap(u,v);
		c[u][v]++;
	}
	
	
	set<int>ans;
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n;j++) 
		if(c[i][j]==2)
		{
			ans.insert(2);
		}
	}
	ans.insert(1);
	
	for(int i=1;i<(1<<n);i++)
	{
		vector<int>a;
		for(int j=0;j<n;j++)
		{
			if(i>>j&1) a.push_back(j);
		}
		
		if(a.size()==1) continue;
		
		do
		{		
			int f=d[a.back()][a[0]];
			for(int k=1;k<a.size();k++) f+=d[a[k-1]][a[k]];
			if(f==a.size()) 
			{
				ans.insert(f);
			}
		}while(next_permutation(a.begin(),a.end()));
	}
	
	
	cout<<*ans.rbegin()<<" ";
	if(ans.size()==1) cout<<0<<"\n";
	else 
	{
		auto it=ans.rbegin();
		it--;
		cout<<*it<<"\n";
	}
//	for(auto i:ans) cout<<i<<" ";
//	cout<<"??\n";
//	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
