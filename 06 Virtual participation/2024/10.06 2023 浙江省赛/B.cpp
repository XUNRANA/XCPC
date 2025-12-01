#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s,t="";
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(i+2<s.size()&&s.substr(i,3)=="cjb")
		{
			t+="cjb,";
			i+=2;
		}
		else t+=s[i];
	}
	cout<<t<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
