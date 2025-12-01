#include <bits/stdc++.h>
using namespace std;
int n,t1,a[100010],b[100010],c[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) c[i]=b[i]=a[i];
	for(int i=2;i<=n;i++) c[i]=c[i-1]%c[i];
	if(c[n]!=0) 
	{
		cout<<"YES\n";
		return ;
	}
	for(int i=2;i<=n;i++)
	{
		if(b[i]%a[1]>0&&b[i]%a[1]<a[2]) 
		{
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
