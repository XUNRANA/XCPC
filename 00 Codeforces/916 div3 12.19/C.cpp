#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200010
int a[N],b[N],ans,n,k;
void solve()
{
	ans=0;
	cin>>n>>k;
	a[0]=b[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;i++) cin>>b[i],b[i]=max(b[i],b[i-1]);
	for(int i=1;i<=min(k,n);i++) ans=max(a[i]+(k-i)*b[i],ans);
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
1
5 10
5 5 5 5 5
1 1 4 1 1
*/
