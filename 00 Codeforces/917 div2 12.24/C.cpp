#include <bits/stdc++.h>
using namespace std;
long long n,k,d,a[2010],b[100010],cnt,ans; 
void solve()
{
	ans=0;
	cin>>n>>k>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++) cin>>b[i];
	for(int i=0;i<=min(2*n,d-1);i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++) if(a[j]==j) cnt++;
		ans=max(ans,cnt+(d-i-1)/2);
		for(int j=1;j<=b[i%k+1];j++) a[j]++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}

