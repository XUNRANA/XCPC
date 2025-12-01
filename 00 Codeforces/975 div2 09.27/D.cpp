#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=n;
	int ll=1,rr=n;
	while(l<=r)
	{
		rr=min(rr,a[l]+l-1);
		ll=max(ll,l-a[l]+1);
		
		ll=max(ll,r-a[r]+1);
		rr=min(rr,r+a[r]-1);
		
		if(a[l]>=r-l+1&&a[r]>=r-l+1) l++,r--;
		else if(a[l]>=r-l+1) l++;
		else if(a[r]>=r-l+1) r--;
		else
		{
			cout<<"0\n";
			return ;
		}
	}
	cout<<max(rr-ll+1,0)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
