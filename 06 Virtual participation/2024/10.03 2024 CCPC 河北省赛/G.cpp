#include <bits/stdc++.h>
using namespace std;
string s;
int c00,c01,c11;
void add(int l,int r)
{
	if(s[l]==s[r])
	{
		if(s[l]=='1') c11++;
		else c00++;
	}
	else c01++;
}
void sub(int l,int r)
{
	if(s[l]==s[r])
	{
		if(s[l]=='1') c11--;
		else c00--;
	}
	else c01--;
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	cin>>s;
	int l=s.size();
	s=s+s;
	s=" "+s;
	int ans=0;
	c00=c01=c11=0;
	for(int i=1,j=1;j<=l&&i<=2*l;)
	{
		add(i,i+1);
		i+=2;
		while(c00>n||c01>m||c11>k||i-j>l)
		{
			sub(j,j+1);
			j+=2;
		}
		if(j<=l&&i<=2*l) ans=max(ans,i-j);
	}
	c00=c01=c11=0;
	for(int i=2,j=2;j<=l&&i<=2*l;)
	{
		add(i,i+1);
		i+=2;
		while(c00>n||c01>m||c11>k||i-j>l)
		{
			sub(j,j+1);
			j+=2;
		}
		if(j<=l&&i<=2*l) ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
