#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int l,r,y;
}a[200010];
bool cmp(node a1,node a2)
{
	if(a1.y==a2.y) return a1.l<a2.l;
	return a1.y>a2.y;
}
int n,x,y; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r>>a[i].y;
	sort(a+1,a+1+n,cmp);
	cin>>x>>y;
	for(int i=1;i<=n;i++)
	{
		if(a[i].y>y) continue;
		if(a[i].l<x&&x<a[i].r)
		{
			x=a[i].r;
			y=a[i].y;
		}
	}
	cout<<x<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}


