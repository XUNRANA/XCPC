#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,x,y;
struct node
{
	int x,y;
}a[200010];
bool cmp(node a1,node a2)
{
	if(a1.x==a2.x) return a1.y<a2.y;
	return a1.x<a2.x;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k-1;i++)
	{
		if(a[i+1].x<a[i].x||a[i+1].y<a[i].y)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
