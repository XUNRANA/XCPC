#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];
struct node
{
	int l,r;
}p[500010];
bool cmp(node p1,node p2)
{
	if(p1.l==p2.l) return p1.r<p2.r;
	return p1.l<p2.l;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>p[i].l>>p[i].r;
	sort(p+1,p+1+m,cmp);
	vector<int>dp(n+1);
	dp[1]=a[1];
	
}
int main()
{
	int T;
	cin>>T;
	while(T--) solve();  
}
