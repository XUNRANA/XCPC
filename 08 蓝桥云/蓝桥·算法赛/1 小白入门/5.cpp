#include <bits/stdc++.h>
using namespace std;
int n,a[5010],p[5010],s[5010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	a[0]=-1;
	a[n+1]=1e9+1; 
	for(int i=1;i<=n;i++)//以i结尾的LIS 
	{
		p[i]=1;
		for(int j=1;j<i;j++)
		if(a[i]>a[j]) p[i]=max(p[i],p[j]+1);
	}
	for(int i=n;i>=1;i--)//以i开头的LIS 
	{
		s[i]=1;
		for(int j=n;j>i;j--)
		if(a[i]<a[j]) s[i]=max(s[i],s[j]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,p[i]),ans=max(ans,s[i]);
	for(int i=0;i<=n+1;i++)
	{
		for(int j=i+2;j<=n+1;j++)
		if(a[i]==a[j]+1) ans=max(ans,p[i]+s[j]);
		else if(a[i]<=a[j]-2) ans=max(ans,p[i]+s[j]+1);
	}
	cout<<ans<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
