#include <bits/stdc++.h>
using namespace std;
int n,a[100010],c[3],t;
long long ans;
string s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>s>>a[i];
		if(s=="fire") c[0]++;
		else if(s=="thunder") c[1]++;
		else if(s=="ice") c[2]++;
	}
	sort(a+1,a+1+n);
	t=min(n/2,n-max({c[0],c[1],c[2]}));
	for(int i=1;i<=n;i++)
	{
		if(i>=n-t+1) ans+=a[i];
		ans+=a[i];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
