#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long 
int n,k,op,x,s,s1,ans,a[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	while(k--)
	{
		cin>>op>>x;
		if(op==1) s+=x,s1+=x;
		else s-=x,s1=max(0ll,s1-x);           
	}
	for(int i=1;i<=n;i++) ans=(ans+max(a[i]+s,s1))%P;
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
