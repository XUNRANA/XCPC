#include <bits/stdc++.h>
using namespace std;
int n1,n2,k;
int a[1010],b[1010],ans;
void solve()
{
	ans=0;
	cin>>n1>>n2>>k;
	for(int i=1;i<=n1;i++) cin>>a[i];
	for(int i=1;i<=n2;i++) cin>>b[i];
	sort(a+1,a+1+n1);
	sort(b+1,b+1+n2);
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(a[i]+b[j]<=k) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
