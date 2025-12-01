#include <bits/stdc++.h>
using namespace std;
long long n,k,s,a[200010],h[200010],ans;
void solve()
{
	ans=s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1,j=1;i<=n&&j<=n;i++)
	{
		s+=a[i];
		while(s>k) s-=a[j++];
		ans=max(ans,i-j+1ll);
		if(i+1<=n&&h[i]%h[i+1]!=0) s=0,j=i+1;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
