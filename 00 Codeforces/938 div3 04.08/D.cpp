#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,ans,t;
int a[200010];
void solve()
{
	l=ans=0;
	cin>>n>>m>>k;
	map<int,int>mb,ma;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
	{
		cin>>t;
		mb[t]++;
	}
	
	for(int i=1;i<=m;i++)
	{
		ma[a[i]]++;
		if(mb.count(a[i])&&ma[a[i]]<=mb[a[i]]) l++;
	}
	if(l>=k) ans++;
	//cout<<ans<<"\n";
	for(int i=m+1;i<=n;i++)
	{
		if(mb.count(a[i-m])&&ma[a[i-m]]<=mb[a[i-m]]) l--;
		ma[a[i-m]]--;
		
		ma[a[i]]++;
		if(mb.count(a[i])&&ma[a[i]]<=mb[a[i]]) l++;
		if(l>=k) ans++;	
		//cout<<l<<" "<<k<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
