#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
	/* 
2
3
9 99 999
1
12345
	*/
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int s=a[1],ans=0;
	for(int i=2;i<=n;i++)
	{
		int ts=s;
		int ta=a[i];
		
		int c=0;
		while(ts||ta)
		{
			int t=ts%10+ta%10+c;
			if(t>=10) ans++;
			c=t/10;
			ts/=10;
			ta/=10;
		}
		
		s+=a[i];
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
