#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
bool ck1(int i)
{
	if(i-1>=1&&a[i-1]==a[i]) return 1;
	return 0;
}
bool ck2(int i)
{
	if(i+1<=n&&a[i+1]==a[i]) return 1;
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++) 
	if(a[i]!=a[n-i+1])
	{
		if(ck1(i)||ck2(n-i+1))
		{
			swap(a[i],a[n-i+1]);
		}
	}	

	int ans=0;
	for(int i=2;i<=n;i++) if(a[i]==a[i-1]) ans++;
	
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
