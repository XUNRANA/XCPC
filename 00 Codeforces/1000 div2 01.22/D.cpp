#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,m,a[N],b[N],pa[N],pb[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[n-i+1]-a[i];
	for(int i=1;i<=m;i++) pb[i]=pb[i-1]+b[m-i+1]-b[i];
	vector<int>ans;
	//ka+kb=x;

	//2*ka+kb<=n
	//ka+2*kb<=m
	//2*x-m<=ka<=n-x
	for(int x=1;2*x-m<=n-x;x++)
	{
		int l=max(0ll,2*x-m),r=min(x,n-x);//ka的范围
		if(l>r) break;
		auto f=[&](int ka) {return pa[ka]+pb[x-ka];};
		
		while(r-l>3)
		{
			int ml=(l*2+r)/3,mr=(l+r*2)/3;
			if(f(ml)>f(mr)) r=mr;
			else l=ml;
		}

		int res=0;
		for(int i=l;i<=r;i++) res=max(res,f(i));
		ans.push_back(res); 
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
