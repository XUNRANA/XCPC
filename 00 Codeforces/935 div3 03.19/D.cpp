#include <bits/stdc++.h>
using namespace std;
long long n,k,a[200010],b[200010],ans,res;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	
	for(int i=1;i<=n;i++) cin>>b[i];

	
	
	ans=0;
	for(int i=k+1;i<=n;i++) ans+=min(a[i],b[i]);
	
	res=ans+a[k];
	
	for(int i=k;i>=1;i--)
	{
		res=min(res,ans+a[i]);
		ans+=min(a[i],b[i]);
	}
	cout<<res<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
