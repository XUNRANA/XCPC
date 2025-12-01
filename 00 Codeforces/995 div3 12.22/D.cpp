#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,a[200010];
void solve()
{
	cin>>n>>x>>y;
	int s=0,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int ts=s-a[i];
		
		int high=ts-x;//至多 
		int low=ts-y;//至少 
		
		int j=upper_bound(a+1,a+1+n,high)-a;
//		1 2 3 4
//	          0
		int i1=lower_bound(a+1,a+1+n,low)-a;
		ans+=j-i1;
		if(i>=i1&&i<j) ans--; 
//		y>=ts-t>=x;
		
//		t<=ts-x;
		
//		t>=ts-y;
	}
	cout<<ans/2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
