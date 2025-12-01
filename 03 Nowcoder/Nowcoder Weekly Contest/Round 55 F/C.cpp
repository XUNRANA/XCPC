#include <bits/stdc++.h>
using namespace std;
long long n,a[500010];
void solve()
{ 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++)
	{
		if(a[i-1]*a[i]>=a[i]*a[i+1])
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

