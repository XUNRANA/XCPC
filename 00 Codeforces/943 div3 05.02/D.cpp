#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,b,s,sb,ss,ab,as,ma,ms;
int p[200010],a[200010];
void solve()
{
	cin>>n>>k>>b>>s;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	sb=ss=0;
	
	ab=a[b]*k;
	as=a[s]*k;
	
	ma=a[b];
	ms=a[s];
	for(int i=1;i<=min(k-1,n-1);i++)
	{
		sb+=a[b];
		ss+=a[s];
		b=p[b];
		s=p[s];
		ma=max(ma,a[b]);
		ms=max(ms,a[s]);
		ab=max(ab,sb+(k-i)*ma);
		as=max(as,ss+(k-i)*ms);
	}
	//cout<<ab<<" "<<as<<"\n";
	if(ab==as) cout<<"Draw\n";
	else if(ab>as) cout<<"Bodya\n";
	else cout<<"Sasha\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
