#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,ans1,ans2,a[1010],jc[1010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=1000;i++) jc[i]=jc[i-1]*i%P;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans1+=a[j]-a[i];
		}
	}
	
	if(a[1]==a[n]) cout<<ans1<<" "<<jc[n]<<"\n";
	else 
	{
		ans2=2;
		map<int,int>cnt;
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		for(auto i:cnt) ans2=ans2*jc[i.second]%P;
		cout<<ans1<<" "<<ans2<<"\n";
	}
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
