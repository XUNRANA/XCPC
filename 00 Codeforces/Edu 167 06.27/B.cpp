#include <bits/stdc++.h>
using namespace std;
int fx(string a,string b)
{
	int j=0;
	for(auto i:a)
	{
		if(j<b.size()&&b[j]==i) j++;
	}
	return j;
}
void solve()
{
	int n;
	string s,t;
	cin>>s>>t;
	int ans=s.size()+t.size();
	for(int i=0;i<t.size();i++)
	{
		string p=t.substr(i);
		ans=min(ans,(int)t.size()-fx(s,p)+(int)s.size());
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
