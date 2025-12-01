#include <bits/stdc++.h>
using namespace std;
int n,ans,a[50010];
void solve()
{
	ans=1e9;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) ans=min(ans,max(a[i],a[i+1]));
	cout<<ans-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
