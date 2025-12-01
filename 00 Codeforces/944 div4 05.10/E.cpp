#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,q,a[100010],b[100010],x,ans;
void solve()
{
	a[0]=b[0]=0;
	cin>>n>>k>>q;
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<=k;i++) cin>>b[i];
	while(q--)
	{
		cin>>x;
		int i=lower_bound(a+1,a+1+k,x)-a;
		ans=b[i-1]+(b[i]-b[i-1])*(x-a[i-1])/(a[i]-a[i-1]);
		cout<<ans<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
