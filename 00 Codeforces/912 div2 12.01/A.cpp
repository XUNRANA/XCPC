#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,mx,a[110];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k>=2) cout<<"YES\n";
	else 
	{
		for(int i=1;i<n;i++) 
		if(a[i]>a[i+1])
		{
			cout<<"NO\n";
			return ;
		}
		cout<<"YES\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
