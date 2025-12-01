#include <bits/stdc++.h>
using namespace std;
int n,k,mi,t,res;
struct node
{
	int w,i;
	string s;
}a[100010];
int ans[100010];
bool cmp(node a1,node a2)
{
	return a1.w>a2.w;
}
void solve()
{
	cin>>n>>k;
	mi=1e9;
	for(int i=1;i<=k;i++) 
	{
		cin>>t;
		mi=min(mi,t);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w>>a[i].s;
		a[i].i=i;
	}
	sort(a+1,a+1+n,cmp);
	map<string,int>mp;
	res=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[a[i].s]<mi) res++,mp[a[i].s]++;
		ans[a[i].i]=res;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
