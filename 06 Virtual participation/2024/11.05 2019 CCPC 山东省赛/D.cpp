#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]==a[n]) cout<<"0\n";
	else
	{
		int s=0;
		
		for(int i=1;i<=n;i++) s+=a[i];
		
		int p=s/n,s1=0,s2=0;
		for(int i=1;i<=n;i++) 
		if(a[i]==p) continue;
		else if(a[i]<p) s1+=p-a[i];
		else if(a[i]>p) s2+=a[i]-p;
		
		cout<<max(s1,s2)<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
