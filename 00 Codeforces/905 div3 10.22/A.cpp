#include <bits/stdc++.h>
using namespace std;
int x,ans,p;
string s;
void solve()
{
	cin>>s;
	ans=0;
	p=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') x=10;
		else x=s[i]-'0';
		ans+=abs(x-p)+1;
		p=x;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
