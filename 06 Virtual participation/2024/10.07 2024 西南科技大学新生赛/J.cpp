#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,i;
}a[500010];
bool cmp(node a1,node a2)
{
	if(a1.x==a2.x) return a1.i<a2.i;
	return a1.x>a2.x;
}
int n,t,s;
void solve()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+1+n,cmp);
	s=0;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i].x>t)
		{
			cout<<"YES\n";
			cout<<i<<"\n";
			for(int j=1;j<=i;j++) cout<<a[j].i<<" ";
			cout<<"\n";
			return ;
		}
		s+=a[i].x;
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
