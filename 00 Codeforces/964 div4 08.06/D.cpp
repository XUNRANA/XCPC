#include <bits/stdc++.h>
using namespace std;
string s,t;
void solve()
{
	cin>>s>>t;
	int j=0;
	for(auto &i:s)
	{
		if(t[j]==i) j++;
		else if(i=='?') 
		{
			if(j<t.size())
			{
				i=t[j];
				j++;
			}
			else i='a';
		}
	}
	if(j>=t.size()) 
	{
		cout<<"YES\n";
		cout<<s<<"\n";
	}
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
