#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[200010];
bool ck(int x)
{
	int s=0,res=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(res+a[i]*s>x)
		{
			cnt++;
			res=0;
			s=a[i];
		}
		else
		{
			res+=a[i]*s;
			s+=a[i];
		}
		if(cnt>m) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0,r=2e18;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 



