#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	vector<int>a;
	int s;
}a[200010];
bool cmp(node a1,node a2)
{
	return a1.s>a2.s;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		a[i].a.clear();
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			s+=x;
			a[i].a.push_back(x);
		}
		a[i].s=s;
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	int l=n*m;
	for(int i=1;i<=n;i++)
	{
		for(auto k:a[i].a)
		{
			ans+=k*l;
			l--;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
