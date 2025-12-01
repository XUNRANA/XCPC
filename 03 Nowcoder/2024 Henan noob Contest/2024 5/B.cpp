#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[1000010],l,r,s1,s2;
void solve()
{
	s=s1=s2=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s+=a[i];
	}
	cin>>l>>r;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<l) s1+=l-a[i];
		if(a[i]>r) s2+=a[i]-r;
	}
	if(l*n<=s&&s<=r*n) cout<<max(s1,s2)<<"\n";
	else cout<<"-1\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
