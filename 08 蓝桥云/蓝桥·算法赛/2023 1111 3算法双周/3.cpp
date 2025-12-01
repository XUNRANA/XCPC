#include <bits/stdc++.h>
using namespace std;

map<char,int>mp;
void solve()
{
	string a,b;
	cin>>a>>b;
	if(a[0]==a[1]||a[0]=='M'&&a[1]=='F'||a[0]=='F'&&a[1]=='M'||max(mp[a[0]],mp[a[1]])>=max(mp[b[0]],mp[b[1]])&&!(b[0]=='M'&&b[1]=='F')&&!(b[0]=='F'&&b[1]=='M')) cout<<"ShallowDream\n";
	else cout<<"Joker\n";
}
int main()
{
  string p="3456789XJQKA2MF";
	int j=0;
	for(auto i:p) mp[i]=j++;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
