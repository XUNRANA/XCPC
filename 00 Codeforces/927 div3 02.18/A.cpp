#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
void solve()
{
	ans=0;
	cin>>n>>s; 
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='@') ans++;
		else if(s[i]=='*'&&s[i+1]=='*') break;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
