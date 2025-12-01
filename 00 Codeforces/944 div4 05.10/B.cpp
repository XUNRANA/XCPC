#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=s[0])
		{
			swap(s[i],s[0]);
			cout<<"YES\n"<<s<<"\n";
			return ;
		}
	}
	cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
