#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(s[0]==s[2]&&s[2]!=s[3]||s[0]!=s[1]&&s[1]==s[3]) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
