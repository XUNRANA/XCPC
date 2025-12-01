#include <bits/stdc++.h>
using namespace std;
int n,a[51];
void solve()
{
	cin>>n;
	if(n<=50) cout<<a[n]<<"\n";
	else cout<<min({n/15+a[n%15],n/15-1+a[15+n%15],n/15-2+a[30+n%15]})<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=50;i++) a[i]=1e9;
	a[1]=a[3]=a[6]=a[10]=a[15]=1;
	for(int i=1;i<=50;i++)
	{
		if(i>1) a[i]=min(a[i],a[i-1]+1);
		if(i>3) a[i]=min(a[i],a[i-3]+1);
		if(i>6) a[i]=min(a[i],a[i-6]+1);
		if(i>10) a[i]=min(a[i],a[i-10]+1);
		if(i>15) a[i]=min(a[i],a[i-15]+1);
	}
	int t;
	cin>>t;
	while(t--) solve();
}
