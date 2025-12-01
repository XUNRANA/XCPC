#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int>s,p;
vector<int>e[N];
int n,t;
string a;
void dfs(int u)
{
	if(a[u]=='S') s[u]=0;
	else if(a[u]=='P') p[u]=0;
	else s[u]=p[u]=0;
	for(auto i:e[u])
	{
		dfs(i);
		s[u]+=min(s[i],p[i]+1);
		p[u]+=min(p[i],s[i]+1);
	}
	return ;
}
void solve()
{
	cin>>n;
	s.clear();
	p.clear();
	s.resize(n,n);
	p.resize(n,n);
	for(int i=0;i<n;i++) e[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>t;
		t--;
		e[t].push_back(i);
	}
	cin>>a;
	dfs(0);
	if(a[0]=='S') cout<<s[0]<<"\n";
	else if(a[0]=='P') cout<<p[0]<<"\n";
	else cout<<min(s[0],p[0])<<"\n";
}
 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
