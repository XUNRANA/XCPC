#include <bits/stdc++.h>
using namespace std;
int n,ans,a,b,L[200010],R[200010],l,r,m;
int ck(int x)
{
	a=0,b=0;
	for(int i=1;i<=n;i++)
	{
		a-=x;
		b+=x;
		if(b<L[i]||a>R[i]) return 0;
		a=max(a,L[i]);
		b=min(b,R[i]);
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>L[i]>>R[i];
	l=0,r=1e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
