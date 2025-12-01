#include <bits/stdc++.h>
using namespace std;
#define int long long
int mi,n,k,a[2010],d,l;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	mi=a[1];
	for(int i=1;i<=n;i++) mi=min(mi,a[i]-a[i-1]);
	
	if(k>=3) cout<<"0\n";
	else if(k==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				d=a[j]-a[i];
				l=lower_bound(a+1,a+1+n,d)-a;
				if(l<=n) mi=min(mi,abs(a[l]-d));
				if(l-1>=1) mi=min(mi,abs(a[l-1]-d));
			}
		}
		cout<<mi<<"\n";
	}
	else if(k==1) cout<<mi<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
