#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=5e5+10;
int n,a[N],b[N],c[N];
double in(int x,int y)
{
	return (double)(y-b[x])/a[x];
}
bool cmp(double x,double y)
{
	return x>y;
}
bool ck(int x)
{
	vector<double>k1,k2;
	int cnt=0;
	for(int i=1;i<=n;i++) 
	if(a[i]>0) k1.push_back(in(i,x));
	else if(a[i]<0) k2.push_back(in(i,x));
	else cnt+=(b[i]>=x);
	
	sort(k1.begin(),k1.end(),cmp);
	sort(k2.begin(),k2.end());
	int l=1;
	for(auto u:k2) if(u>=c[l]) l++,cnt++;//斜率为负，更小 
	l=n;
	for(auto u:k1) if(u<=c[l]) l--,cnt++;//斜率为正，更大 
	return (cnt>=(n+1)/2);//中位数 
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	int l=-2e18,r=2e18;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	} 
	cout<<l-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
