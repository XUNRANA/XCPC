#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,a[100010],ans,mx,f[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t;
		f[t]=1;
        mx=max(mx,t);
	}
    if(mx==0)
    {
        cout<<"0\n";
        return ;
    }
	for(int i=0;i<=n;i++) 
	if(!f[i]) 
	{
		ans=i;
		break;
	}
	for(int i=1;i<=n;i++) 
	if(!a[i]) 
	{
		if(i-1>=1) ans=max(ans,a[i-1]);
		if(i+1<=n) ans=max(ans,a[i+1]);
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
