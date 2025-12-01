#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x;
int a[300010];
int c[300010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cur=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		if(x<=cur) c[i]=1;
		else c[i]=n-(lower_bound(a+1,a+1+n,x)-a)+2;
	}
	sort(c+1,c+1+m);
	for(int k=1;k<=m;k++)
	{
		int ans=0;
		for(int i=k;i<=m;i+=k) ans+=c[i];
		cout<<ans<<" ";
	}
	cout<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

