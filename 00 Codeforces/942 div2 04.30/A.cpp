#include <bits/stdc++.h>
using namespace std;
int ans,n,a[110],b[110];
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	while(1)
	{
		int f=0;
		for(int i=1;i<=n;i++) if(a[i]>b[i]) f=1;
		if(f==0) break;
		ans++;
		for(int i=n;i>=2;i--) a[i]=a[i-1];
		a[1]=1;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
