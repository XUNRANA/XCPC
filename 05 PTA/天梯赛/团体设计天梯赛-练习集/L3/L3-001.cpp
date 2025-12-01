#include <bits/stdc++.h>
using namespace std;
int n,m,f;
vector<int>a;
void dfs(int i,int s,vector<int>&p)
{
	if(f) return ;
	if(s>=m)
	{
		if(s>m) return ;
		int fl=0;
		for(auto i:p)
		{
			if(fl) cout<<" ";
			cout<<i;
			fl=1;
		}
		f=1;
		return ;
	}
	for(int j=i;j<a.size();j++)
	{
		if(a[j]+s<=m)
		{
			p.push_back(a[j]);
			dfs(j+1,s+a[j],p);
			p.pop_back();
		}
	}
}
void solve()
{
	cin>>n>>m;
	int s=0; 
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		s+=x;
		if(x<=m) a.push_back(x);
	}
	if(s<m)
	{
		cout<<"No Solution\n";
		return ;
	}
	sort(a.begin(),a.end());
	vector<int>p;
	dfs(0,0,p);
	if(!f) cout<<"No Solution\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

