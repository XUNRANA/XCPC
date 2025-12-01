#include <bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int>p[200];
vector<int> fx(vector<int>a,vector<int>b)
{
	vector<int>c(n);
	for(int i=0;i<n;i++) c[i]=a[b[i]];
	return c;
}
void solve()//carefully!!!!!!!
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>t;
			p[i].push_back(t-1);
		}
	}
	
	set<vector<int>>ans;
	if(n>=10)
	{
		for(int i=1;i<(1<<m);i++)
		{
			vector<int>a;
			for(int j=0;j<n;j++) a.push_back(j);
			for(int j=0;j<m;j++) if(i>>j&1) a=fx(a,p[j]);	
			ans.insert(a);
		}
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			set<vector<int>>ans1;
			
			for(auto j:ans) ans1.insert(fx(j,p[i]));
			
			ans1.insert(p[i]);
			
			for(auto j:ans1) ans.insert(j);			
		}
	}
	
	cout<<ans.size()<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
