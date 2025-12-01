#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
int b[100010];
int c[100010];

int p[100010];
int s[100010];
bool ck(int x)
{
	c[1]=x;
	for(int i=2;i<=n;i++) c[i]=c[i-1]^b[i];
	for(int i=1;i<=n;i++) p[i]=p[i-1]+(c[i]==0);
	s[n+1]=0;
	for(int i=n;i>=1;i--) s[i]=s[i+1]+(c[i]==1);

	for(int i=1;i<=n;i++)
	if(p[i-1]+s[i+1]+1!=a[i]) return 0;

	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) 
	{
		if(abs(a[i]-a[i-1])>1)
		{
			cout<<"0\n";
			return ;
		}
		if(a[i]==a[i-1]) b[i]=1;
		else b[i]=0;
	}
	int ans=0;
	ans+=ck(0);
	ans+=ck(1);
	cout<<ans<<"\n";
} 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
