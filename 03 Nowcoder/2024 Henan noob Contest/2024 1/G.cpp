#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,r,mid,ans,s,a[200010],b[200010];
int ck(int x)
{
	for(int i=1;i<=x;i++) b[i]=a[i];
	sort(b+1,b+1+x);
	s=0;
	for(int i=1;i<=x-k;i++) 
    {
        s+=b[i];
        if(s>=m) return 0;
    }
	return 1;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=0,r=n;
	while(l<=r)
	{
		mid=l+r>>1;
		if(ck(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
