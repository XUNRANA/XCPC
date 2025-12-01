#include <bits/stdc++.h>
using namespace std;
int n,x;
int a[100];
int p[100];
vector<int>path;
void dfs(int u)
{
	if(2*u<=n) dfs(2*u);
	if(2*u+1<=n) dfs(2*u+1);
	path.push_back(u);
}
void solve()
{
	cin>>n;
	dfs(1);
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		p[path[i-1]]=x;
	}
	int f=0;
	for(int i=1;i<=n;i++) 
	{
		if(f) cout<<" ";
		cout<<p[i];
		f=1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

