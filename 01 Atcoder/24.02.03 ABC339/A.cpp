#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	cout<<s.substr(s.rfind('.')+1,s.size()-s.rfind('.'));
}
int main()
{
	int t;
	t=1;
	//cin>>t;
	while(t--) solve();
}
