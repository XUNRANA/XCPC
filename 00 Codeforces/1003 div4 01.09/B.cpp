#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	char p='.';
	for(auto i:s)
	{
		if(i==p) 
		{
			cout<<"1\n";
			return ;
		}
		p=i;
	}
	cout<<s.size()<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
