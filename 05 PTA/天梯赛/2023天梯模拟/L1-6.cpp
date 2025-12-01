#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		string s;
		getline(cin,s);
		if(s.back()=='?')
		{
			int f=0;
			for(int i=0;i<s.size();i++)
			if(i+2<s.size()&&s.substr(i,3)=="PTA")
			{
				f=1;
				cout<<"Yes!\n";
				break;
			}
			if(!f) cout<<"No.\n";
		}
		else cout<<"enen\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
