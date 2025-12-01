#include <bits/stdc++.h>
using namespace std;
int n,cnt;
char ch;
string s;
void solve()
{
	cnt=0;
	s="";
	cin>>n;
	while(n--) cin>>ch,s=s+ch;
	for(int i=s.find('1');i<=s.rfind('1');i++) if(s[i]=='0') cnt++;
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
