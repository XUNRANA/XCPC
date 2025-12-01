#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],b[200010];
struct node
{
	int v,i;
}c[200010];
bool cmp(struct node c1,struct node c2)
{
	return c1.v<c2.v;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) c[i].v=a[i]+b[i],c[i].i=i;
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++) cout<<a[c[i].i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<b[c[i].i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
