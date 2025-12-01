#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100010],b[100010],ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],ans+=a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	vector<int>c;
	for(int i=1;i<=n;i++) c.push_back(b[i]-a[i]);
	sort(c.begin(),c.end());
	for(auto i:c)
	{
		if(k==0||i>=0) break;
		ans+=i;
		k--;
	}
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
