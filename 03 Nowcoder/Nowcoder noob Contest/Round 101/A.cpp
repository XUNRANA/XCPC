#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[5010],ans;
void solve()
{
	cin>>n>>k;
	k=n-k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	ans=0;
	for(int i=1;i+k-1<=n;i++) ans=max(ans,a[i+k-1]-a[i-1]);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
