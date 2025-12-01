#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n-1;i>=1;i--) a[i]+=a[i+1];
	ans=a[1]; 
	for(int i=2;i<=n;i++) if(a[i]>0) ans+=a[i];
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
