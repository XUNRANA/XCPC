#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[200010],b[200010];
struct node
{
	int x,y;
}c[200010];
bool cmp(node c1,node c2)
{
	if(c1.x==c2.x)
	{
		return a[c1.y]>a[c2.y];
	}
	return c1.x>c2.x;
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]--;
	for(int i=1;i<=n;i++) cin>>b[i],b[i]=-b[i]+1,c[i].x=a[i]-b[i],c[i].y=i;
	/*for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<"\n";*/
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		//cout<<c[i].y<<" ";
		if(i&1) ans+=a[c[i].y];
		else ans+=b[c[i].y];
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
/*
A:0    19   0    19
B:-99  -14  -9  -19

99 33 9 36
*/
