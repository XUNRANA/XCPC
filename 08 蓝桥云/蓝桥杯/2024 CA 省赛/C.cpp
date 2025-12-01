#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int p,s,suf;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.s==a2.s) return a1.p<a2.p;
	return a1.s<a2.s;	
}
int n,s;
void solve()
{
	int ans=0,res=0;
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i].p>>a[i].s;
	sort(a+1,a+1+n,cmp);
	a[n].suf=a[n].p;
	for(int i=n-1;i>=1;i--) a[i].suf=a[i+1].suf+a[i].p;
	ans=a[n].s*s;
	for(int i=1;i<=n;i++)
	if(a[i].suf<s)
	{
		int x=a[i-1].s;
		ans=x*s;
		for(int j=i;j<=n;j++) ans+=(a[j].s-x)*a[j].p;
		break;
	}
	cout<<ans<<"\n";
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
