#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,k,a[1000100],b[1000100],p,c[1000100],cnt,ans;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		cin>>k;
		for(int i=1;i<=n;i++) b[i]=a[i];
		
		for(int i=60;i>=0;i--)
		{
			cnt=0;
			for(int j=1;j<=n;j++) c[j]=b[j];
			for(int j=1;j<=n;j++)
			{
				if(!((b[j]>>i)&1))
				{
					p=((b[j]>>i)+1)<<i;
					cnt+=p-b[j];
					b[j]=p;
				}
				if(cnt>k) break;
			}
			if(cnt<=k) k-=cnt;
			else for(int j=1;j<=n;j++) b[j]=c[j];
		}
		ans=b[1];
		for(int j=1;j<=n;j++) ans&=b[j];
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	while(t1--) solve();
}
