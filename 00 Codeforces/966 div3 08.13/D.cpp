#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],d[200010];
int n,ans;
string s;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],d[i]=0;
	cin>>s;
	s=" "+s;
	for(int i=1,j=n;i<j;)
	{
		if(s[i]=='L'&&s[j]=='R')
		{
			d[i]++;
			d[j+1]--;
			i++;
			j--;			
		}
		while(s[i]!='L'&&i<j) i++;
		while(s[j]!='R'&&i<j) j--;
	}
	for(int i=1;i<=n;i++) 
	{
		d[i]+=d[i-1];
		ans+=d[i]*a[i];
	}
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
