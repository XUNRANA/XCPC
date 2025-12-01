#include <bits/stdc++.h>
using namespace std;
#define int long long
int dis(int x,int y)
{
	return x*x+y*y;
}
void solve()
{
	int n,k,x,y,r;
	cin>>n>>k;
	vector<double>v;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>r;
		if(dis(x,y)<r*r) v.push_back((1.0*r-1.0*sqrt(dis(x,y)))*r*r);
	}
	sort(v.begin(),v.end());
	double ans=0;
	for(int i=0;i<v.size()-k;i++) ans+=v[i];
	printf("%.15f\n",ans*3.14159265358979324);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
