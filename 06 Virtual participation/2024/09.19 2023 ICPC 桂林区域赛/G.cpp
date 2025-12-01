#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	int c=0;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--) 
	{
		if(s[i]==')') c++;
		else c--;
		if(c<0) 
		{
			cout<<"impossible\n";
			return ;
		}
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
