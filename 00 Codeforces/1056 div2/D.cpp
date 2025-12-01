#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r;
int a[300010];
int p[300010];
int s[300010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]+__lg(a[i]);
		s[i]=s[i-1];

		if((a[i]-1)&a[i])
		{
			if((a[i]-2)&(a[i]-1)) p[i]++;
			else s[i]++;
		}
	}
	while(q--)
	{
		cin>>l>>r;
		cout<<p[r]-p[l-1]+(s[r]-s[l-1])/2<<"\n";
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
