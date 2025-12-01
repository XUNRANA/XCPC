#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[32];
void solve()
{
	cin>>n;
	if(n%4==0)
	{
		cout<<"NO\n";
		return ;
	}
	for(int i=0;i<=31;i++) a[i]=1;// (1<<32)-1	
	int t=(1ll<<32)-1-n;
	
	for(int i=1;i<=31;i++) if(t>>i&1) a[i-1]=-1;
	cout<<"YES\n";
	if(n%2==0) a[0]=0;
	for(int i=0;i<=31;i++)
	{
		cout<<a[i]<<" ";
		if((i+1)%8==0) cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
