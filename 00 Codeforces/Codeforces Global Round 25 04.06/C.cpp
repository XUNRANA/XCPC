#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,a[300010],ans;
void solve()
{
	ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(k>m) k-=m,l=m;
		else l=k,k=0;
		ans+=a[i]*l+k*l;
		//cout<<a[i]<<" "<<l<<" "<<k<<" "<<ans<<"\n";
		if(k==0) break;
	}
	cout<<ans<<"\n";

}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
