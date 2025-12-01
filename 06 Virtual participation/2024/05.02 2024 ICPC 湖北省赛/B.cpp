#include <bits/stdc++.h>
using namespace std;
#define int long long

double f(int x1,int y1,int x2,int y2,int x3,int y3)
{
	if((x3-x2)*(y2-y1)==(y3-y2)*(x2-x1)) return 1e18;
	return 0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}
void solve()
{
	int n;
	cin>>n;
	double ans=1e18;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				//cout<<f(a[i].first,a[i].second,a[j].first,a[j].second,a[k].first,a[k].second)<<"\n";
				ans=min(ans,f(a[i].first,a[i].second,a[j].first,a[j].second,a[k].first,a[k].second));
			}
		}
	}
	if(ans==1e18) ans=-1;
	cout<<ans<<"\n";
}
signed main()
{
	int T=1;
	cin>>T;
	while(T--) solve();
}
