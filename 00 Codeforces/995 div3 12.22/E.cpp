#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int b[200010];

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>c;
//	0--------a  ºÃÆÀ
//	a+1------b  ²îÆÀ
//	b+1------  ²»¹ºÂò 
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		c.push_back(a[i]-1);
		c.push_back(a[i]);
		c.push_back(a[i]+1);
		a[i]++;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
		c.push_back(b[i]-1);
		c.push_back(b[i]);
		c.push_back(b[i]+1);
		b[i]++;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c.begin(),c.end());
	int ans=0;
	for(auto i:c)
	{
//		²îÆÀ:   3       2
//		²»¹ºÂò: 4       5
//		cout<<i<<"\n";
		int p=i;
		int good=upper_bound(a+1,a+1+n,p)-a-1;
		int bad=upper_bound(b+1,b+1+n,p)-b-1;
//		int sum=n-bad;
		good=n-good;
		
		bad=n-bad-good;
		
//	 	cout<<i<<" "<<good<<" "<<bad<<"\n";
		if(bad<=k) ans=max(ans,(good+bad)*p);
//		ans=max(ans,p*cnt);
		
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
