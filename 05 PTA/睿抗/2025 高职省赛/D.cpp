#include <bits/stdc++.h>
using namespace std;
string s[10];
string t;
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	cin>>t;
	string ans="";
	for(int i=0;i<t.size();i++)
	{
		int f=0;
		for(int j=0;j<n;j++)
		{
			if(t.substr(i,s[j].size())==s[j])
			{
				ans+="*"+s[j]+"*";
				i+=s[j].size()-1;
				f=1;
				break;
			}
		}
		if(!f) ans+=t[i];
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
