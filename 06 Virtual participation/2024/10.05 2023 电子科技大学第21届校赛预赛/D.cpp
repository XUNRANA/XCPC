#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
	int x1,y1,x2,y2,s;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.s==a2.s) return a1.x1<a2.x1;
	return a1.s<a2.s;
}
int n,f,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x1;
		cin>>a[i].y1;
		cin>>a[i].x2;
		cin>>a[i].y2;
		a[i].s=a[i].x1+a[i].y1;
	}
	sort(a+1,a+1+n,cmp);
	f=0;
	ans=a[1].x2-a[1].x1;
	int mx=a[1].x2;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s==a[i-1].s)
		{
			if(a[i].x2<=mx) 
			{
				f=1;
				continue;
			}
			if(a[i].x1>=mx)
			{
				ans+=a[i].x2-a[i].x1;
				mx=a[i].x2;
			}
			else 
			{
				ans+=a[i].x2-mx;
				f=1;
				mx=a[i].x2;
			}
		}
		else 
		{
			ans+=a[i].x2-a[i].x1;
			mx=a[i].x2;
		}
	}
	if(f) cout<<"NO\n";
	else cout<<"YES\n";
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

