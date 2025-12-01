#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin>>s;
	for(int i=1;i<s.size();i++) 
	if(s[i]!='0')
	{
		if(stoi(s.substr(0,i))<stoi(s.substr(i))) cout<<s.substr(0,i)<<" "<<s.substr(i)<<"\n";
		else cout<<"-1\n";
		return ;
	}
	cout<<"-1\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
