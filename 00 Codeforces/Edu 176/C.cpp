#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	sort(a+1,a+1+m);
	if(n&1)
	{
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			//i n-i
			int x=lower_bound(a+1,a+1+m,i)-a;
			int y=lower_bound(a+1,a+1+m,n-i)-a;
			x=m-x+1;
			y=m-y+1;
			ans+=x*y-y;	
		}
		cout<<2*ans<<"\n"; 
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			int x=lower_bound(a+1,a+1+m,i)-a;
			int y=lower_bound(a+1,a+1+m,n-i)-a;
			x=m-x+1;
			y=m-y+1;
			if(i==n/2) ans=ans*2+x*y-y;
			else ans+=x*y-y;
		}	
		cout<<ans<<"\n";
	}
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

