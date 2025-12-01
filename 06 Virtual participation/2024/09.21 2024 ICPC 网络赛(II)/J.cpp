#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int w,v,c;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.c*a2.w==a2.c*a1.w) return a1.v<a2.v;
	return a1.c*a2.w<a2.c*a1.w;
}

int n,ans,s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].v>>a[i].c;
	sort(a+1,a+1+n,cmp);
	ans=s=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i].v<<" "<<a[i].c<<" "<<s<<"\n";
		ans+=max(0ll,a[i].v-a[i].c*s);
		s+=a[i].w;
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
