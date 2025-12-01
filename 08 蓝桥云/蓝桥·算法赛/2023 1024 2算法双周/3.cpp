#include <bits/stdc++.h>
using namespace std;
int n,k,ans,h[100010],h1[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>h[i];
	sort(h+1,h+1+n);
	for(int i=1;i<n;i++) h1[i]=h[i+1]-h[i];
	sort(h1+1,h1+n);
	for(int i=1;i<=n-k;i++) ans+=h1[i]; 
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
