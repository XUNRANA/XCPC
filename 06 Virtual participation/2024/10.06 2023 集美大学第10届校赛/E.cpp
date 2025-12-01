#include <bits/stdc++.h>
using namespace std;
struct node
{
	int n;
	vector<int>v;
}a[2010];
int n,t,m,mx;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].n;
		for(int j=1;j<=a[i].n;j++)
		{
			cin>>t;
			a[i].v.push_back(t);
		}
	}
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<min(a[i].n,m);j++)
		{
			mx=max(mx,a[i].v[j]);
		}
	}
	cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
