#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],l,r,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		l=1,r=i-1;
		while(l<=r)
		{
			m=l+r>>1;
			if(a[m]>=i-m+1) r=m-1;
			else l=m+1;
		}
		cout<<i-l+1<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
