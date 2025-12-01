#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	vector<vector<int>>b(n+1,vector<int>(m+1,0));
	map<int,pair<int,int>>mp;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],mp[a[i][j]]={i,j};
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
	
	vector<int>c(m+1);
	set<int>s;
	for(int j=1;j<=m;j++) 
	{
		c[j]=mp[b[1][j]].second;
		s.insert(mp[b[1][j]].first);
	} 
	if(s.size()!=1) 
	{
		cout<<"NO\n";
		return ;
	}
	
	for(int j=1;j<=m;j++)
	{
		set<int>s1,s2;
		for(int i=1;i<=n;i++) s1.insert(b[i][j]);
		
		for(int i=1;i<=n;i++) s2.insert(a[i][c[j]]);
		if(s1.size()!=n||s1!=s2)
		{
			cout<<"NO\n";
			return ;
		}
	}
	
	
	vector<int>d(n+1);
	s.clear();
	for(int i=1;i<=n;i++) 
	{
		d[i]=mp[b[i][1]].first;
		s.insert(mp[b[i][1]].second);
	} 
	
	if(s.size()!=1) 
	{
		cout<<"NO\n";
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		set<int>s1,s2;
		for(int j=1;j<=m;j++) s1.insert(b[i][j]);
		
		for(int j=1;j<=m;j++) s2.insert(a[d[i]][j]);
		if(s1.size()!=m||s1!=s2)
		{
			cout<<"NO\n";
			return ;
		}
	}
	
	
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
