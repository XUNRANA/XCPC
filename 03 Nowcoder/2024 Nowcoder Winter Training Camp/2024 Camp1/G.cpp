#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
	int a,b;
}c[100010];
bool cmp(node c1,node c2)
{
	return c1.a<c2.a;
}
int n,m,mx;
void solve()
{
	cin>>n>>m;
	mx=m;
	for(int i=1;i<=n;i++) cin>>c[i].a>>c[i].b;
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++) 
	{
		c[i].b+=c[i-1].b;
		if(c[i].b+m>=c[i].a) mx=max(mx,c[i].b+m);
	}
	cout<<mx<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
