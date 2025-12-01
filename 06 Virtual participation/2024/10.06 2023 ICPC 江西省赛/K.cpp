#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],s,q,op,k,x,b[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) b[i]=a[i]-a[i+1];
	sort(b+1,b+n,greater<int>());
	for(int i=1;i<n;i++) b[i]+=b[i-1];
	s=b[n-1];
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(op==0) cin>>x;
		else 
		{
			cin>>k;
			cout<<s-b[k-1]<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
