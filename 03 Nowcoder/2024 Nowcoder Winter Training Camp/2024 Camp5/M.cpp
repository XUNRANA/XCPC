#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[100010],b[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	if(n==1)
	{
		cout<<"-1\n";
		return ;
	}
	if(n==2)
	{
		if(a[1]==b[1]) cout<<"-1\n";
		else cout<<"1\n";
        return ;
	}
	ans=2;
	for(int i=2;i<=n-1;i++) 
	{
		if(a[i]==b[i]||a[i]==b[i-1]||a[i]==b[i+1]) ans=1;
		if(b[i]==a[i]||b[i]==a[i-1]||b[i]==a[i+1]) ans=1;
	}
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
