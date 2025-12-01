#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    int c0,c1;
	cin>>s;
	c0=c1=0;
	for(auto i:s) 
	if(i=='0') c0++;
	else c1++;
	for(int i=0;i<s.size();i++)
	if(s[i]=='0') 
	{
		c1--;
		if(c1==-1)
		{
			cout<<s.size()-i<<"\n";
			return ;
		}
	}
	else
	{
		c0--;
		if(c0==-1)
		{
			cout<<s.size()-i<<"\n";
			return ;
		}
	}
	cout<<"0\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
