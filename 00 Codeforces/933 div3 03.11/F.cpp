#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],f[200010],d[200010],mid,n,m,k,mi,mi1,ans,index,cnt;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	mi=0;
	for(int i=1;i<n;i++) 
	{
		if(a[i+1]-a[i]>mi) 
		{
			mi=a[i+1]-a[i];
			index=i;
			cnt=1;
		}
		else if(a[i+1]-a[i]==mi) cnt++;
	}
	
//	cout<<mi<<"\n";
	
	for(int i=1;i<=m;i++) cin>>d[i];
	for(int i=1;i<=k;i++) cin>>f[i];
	
	
	sort(d+1,d+1+m);
	sort(f+1,f+1+k);
	/*
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=k;i++) cout<<f[i]<<" ";
	cout<<"\n";
	*/
	if(cnt>1) cout<<mi<<"\n";
	else
	{
		mi1=0,ans=mi;
		for(int i=1;i<n;i++) 
		{
			if(i==index) continue;
			mi1=max(a[i+1]-a[i],mi1);
		}
		mid=a[index+1]+a[index]>>1;
		//cout<<a[index]<<" "<<mid<<" "<<a[index+1]<<"\n";
		for(int i=1;i<=m;i++)
		{
			if(d[i]>a[index+1]) break;
			int l=lower_bound(f+1,f+1+k,mid-d[i])-f;
			//cout<<d[i]<<" "<<f[l]<<" "<<ans<<"\n";
			if(l>=1&&l<=k&&d[i]+f[l]<=a[index+1]&&d[i]+f[l]>=a[index]) ans=min(ans,max(mi1,max(a[index+1]-(f[l]+d[i]),d[i]+f[l]-a[index])));
			if(l-1>=1&&l-1<=k&&d[i]+f[l-1]<=a[index+1]&&d[i]+f[l-1]>=a[index])ans=min(ans,max(mi1,max(a[index+1]-f[l-1]-d[i],d[i]+f[l-1]-a[index])));
			if(l+1<=k&&l+1>=1&&d[i]+f[l+1]<=a[index+1]&&d[i]+f[l+1]>=a[index]) ans=min(ans,max(mi1,max(a[index+1]-f[l+1]-d[i],d[i]+f[l+1]-a[index])));
		}
		//cout<<ans<<"\n";
		for(int i=1;i<=k;i++)
		{
			if(f[i]>a[index+1]) break;
			int l=lower_bound(d+1,d+1+m,mid-f[i])-d;

			if(l>=1&&l<=m&&f[i]+d[l]<=a[index+1]&&f[i]+d[l]>=a[index]) ans=min(ans,max(mi1,max(a[index+1]-(d[l]+f[i]),f[i]+d[l]-a[index])));
			if(l-1>=1&&l-1<=m&&f[i]+d[l-1]<=a[index+1]&&f[i]+d[l-1]>=a[index])ans=min(ans,max(mi1,max(a[index+1]-d[l-1]-f[i],f[i]+d[l-1]-a[index])));
			if(l+1<=m&&l+1>=1&&f[i]+d[l+1]<=a[index+1]&&f[i]+d[l+1]>=a[index]) ans=min(ans,max(mi1,max(a[index+1]-d[l+1]-f[i],f[i]+d[l+1]-a[index])));
		}
		cout<<ans<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
