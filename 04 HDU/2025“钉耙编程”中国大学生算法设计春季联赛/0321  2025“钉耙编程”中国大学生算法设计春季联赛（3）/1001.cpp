#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,a[100010];
int fx(int a,int b)
{
	int ans=1;
	for(int i=31;i>=0;i--)
	if(b>>i&1)
	{
		ans+=1<<__builtin_popcount(((1<<i)-1)&a);
		if(!(a>>i&1))
		{
			ans--;
			break;
		}
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans=ans*fx(a[i],min(a[i],x))%P;
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
