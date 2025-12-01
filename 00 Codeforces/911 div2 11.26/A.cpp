#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,mx=0,c=0,sum=0;
	string s;
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) 
	if(s[i]=='.') c++,sum++;
	else 
	{
		mx=max(mx,c);
		c=0;
	}
	mx=max(mx,c);
	if(mx>=3) cout<<2<<"\n";
	else cout<<sum<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
