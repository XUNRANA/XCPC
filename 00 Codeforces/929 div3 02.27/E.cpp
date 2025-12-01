#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[100010],l,u,p;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	cin>>q;
	while(q--)
	{
		cin>>l>>u;
		p=upper_bound(a+1,a+1+n,a[l-1]+u)-a;
		if(p==n+1) cout<<n<<" ";
		else if(p==l) cout<<l<<" ";
		else if((a[p]-a[l-1])*(u+u-(a[p]-a[l-1]-1))/2>(a[p-1]-a[l-1])*(u+u-(a[p-1]-a[l-1]-1))/2) cout<<p<<" ";
		else cout<<p-1<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
