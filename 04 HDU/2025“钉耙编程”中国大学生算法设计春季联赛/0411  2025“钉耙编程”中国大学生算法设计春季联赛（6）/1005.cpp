#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int n;
int a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>b;
	for(int i=n-1;i>=1;i--) b.push_back(max(min(a[i]-a[i-1],a[i])-1,0ll));
	// 0 1 2 3 4 5
	int ans=0;
	for(int i=0;i<b.size();i++) if(i%4<=1) ans^=b[i];
	// cout<<ans<<"\n";
	if(!ans) cout<<"Maki\n";
	else cout<<"Taki\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}