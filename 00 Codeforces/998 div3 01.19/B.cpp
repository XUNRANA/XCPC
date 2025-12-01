#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>b;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		vector<int>a;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		b.push_back({a[0],i});
		for(int j=1;j<a.size();j++) if(a[j]-a[j-1]!=n) f=0; 
	}
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++) if(b[i].first!=i) f=0;
	if(f)
	{
		for(auto i:b) cout<<i.second<<" ";
		cout<<"\n";
	}
	else cout<<"-1\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
