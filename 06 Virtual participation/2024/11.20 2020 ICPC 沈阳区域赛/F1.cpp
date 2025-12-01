#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],mx[N],mi[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	mx[1]=a[1];
	for(int i=2;i<=n;i++) mx[i]=max(mx[i-1],a[i]);
	
	mi[n]=a[n];
	for(int i=n-1;i>=1;i--) mi[i]=min(mi[i+1],a[i]);
	
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if(mx[i]<=mi[i+1])
		{
			ans++;
		}
	}
	cout<<ans<<"\n";

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
