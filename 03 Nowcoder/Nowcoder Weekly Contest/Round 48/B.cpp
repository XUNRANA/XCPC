#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(string s)
{
	int ans=0;
	for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) ans++;
	return ans;
}

void solve()
{
	string s;
	cin>>s;
	int ans=0,c=0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=1;i+j-1<s.size();j++)
		{
			//c++;
			ans+=f(s.substr(i,j));
		}
	}
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
