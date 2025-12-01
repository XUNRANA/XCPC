#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
int a[200010],ans;
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	ans=0;
	map<int,int>mp;
	mp[0]++;
	for(int i=1;i<=n;i++)
	{
		if(mp.count(a[i])) ans=(ans+mp[a[i]]*(n-i+1)%P)%P;
		mp[a[i]]+=i+1;
		mp[a[i]]%=P;	
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
