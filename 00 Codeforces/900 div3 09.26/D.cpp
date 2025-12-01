#include <bits/stdc++.h>
using namespace std;
int n,k,q,x,fx,f[200010],l[200010],r[200010];
string s;
void solve()
{
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++) f[i]=0;
	s=" "+s;
	for(int i=1;i<=k;i++) cin>>l[i];
	for(int i=1;i<=k;i++) cin>>r[i];
	cin>>q;
	while(q--)
	{
		cin>>x;
		f[x]^=1;
	}
	for(int i=1;i<=k;i++)
	{
		fx=0;
		for(int j=l[i];2*j<=r[i]+l[i];j++)
		{
			fx^=f[j]^f[r[i]+l[i]-j];
			if(fx) swap(s[j],s[r[i]+l[i]-j]);
		}
	}
	cout<<s.substr(1)<<"\n";
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
