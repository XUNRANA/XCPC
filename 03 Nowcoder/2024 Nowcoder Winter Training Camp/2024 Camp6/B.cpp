#include <bits/stdc++.h>
using namespace std;
int n,ans,x,y,a[100010],b[100010];
void solve()
{
	ans=1e9;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
		int j=upper_bound(a+1,a+1+n,b[i])-a;
		if(j<=n&&a[j]-b[i]<ans)
		{
			ans=a[j]-b[i];
			x=j;
			y=i;
		}
		if(j-1>=1&&b[i]-a[j-1]<ans)
		{
			ans=b[i]-a[j-1];
			x=j-1;
			y=i;
		}
	}
	swap(a[x],a[y]);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}  
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
