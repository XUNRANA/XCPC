#include <bits/stdc++.h>
using namespace std;
int n,s,k,ans,a[100];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	s=ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i]) 
		{
			if(s) s--,ans++;
		}
		else if(a[i]>=k) s+=a[i];
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
