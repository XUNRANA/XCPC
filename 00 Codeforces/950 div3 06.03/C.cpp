#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],d[200010];
void solve()
{
	cin>>n;
	map<int,int>mp;
	set<int>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
		s.insert(b[i]);
		if(a[i]!=b[i]) mp[b[i]]++;
	}
	
	cin>>m;
	for(int i=1;i<=m;i++) cin>>d[i];
	if(s.count(d[m])==0)
	{		
		cout<<"NO\n";
		return ;
	}
	
	for(int i=1;i<=m;i++) 
	if(mp.count(d[i]))
	{
		mp[d[i]]--;
		if(mp[d[i]]==0) mp.erase(d[i]);
	}
	
	if(mp.empty()) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
