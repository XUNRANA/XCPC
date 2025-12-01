#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	if(s.size()==6) cout<<s.substr(0,4)<<"-"<<s.substr(4);
	else
	{
		if((s[0]-'0')*10+(s[1]-'0')<22) cout<<"20"<<s.substr(0,2)<<"-"<<s.substr(2);
		else cout<<"19"<<s.substr(0,2)<<"-"<<s.substr(2);
	}
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

