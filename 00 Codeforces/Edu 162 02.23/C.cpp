#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,len,c[300010],s[300010],s1[300010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		s[i]=s[i-1]+c[i];
		s1[i]=s1[i-1]+(c[i]==1);
	}
	while(q--)
	{
		cin>>l>>r;
		len=r-l+1;
		if(l==r) cout<<"NO\n";
		else if(s1[r]-s1[l-1]>=len/2+1&&s[r]-s[l-1]-(r-l+1)<(s1[r]-s1[l-1])) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
