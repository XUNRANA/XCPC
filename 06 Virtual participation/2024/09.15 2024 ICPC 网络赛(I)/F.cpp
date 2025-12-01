#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,i,lz;
}a[200010];
bool cmpx(node a1,node a2)
{
	if(a1.x==a2.x) return a1.i<a2.i;
	return a1.x>a2.x;
}
int n;
long long ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x,a[i].i=i;
	sort(a+1,a+1+n,cmpx);
	
	for(int i=1;i<=n;i++) 
	if(a[i].x==a[i+1].x) a[i].lz=0;
	else a[i].lz=1;
	
	ans=0;
	set<int>v;
	v.insert(0);
	v.insert(n+1);
	for(int i=1;i<=n;i++)
	{
		auto it=v.upper_bound(a[i].i);
		ans+=a[i].i-(*prev(it))-1;
		if(a[i].lz==0&&a[i+1].i>*it) ans+=*it-a[i].i-1;
		if(a[i].lz==1) ans+=*it-a[i].i-1;
		v.insert(a[i].i);
	}	
	cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
