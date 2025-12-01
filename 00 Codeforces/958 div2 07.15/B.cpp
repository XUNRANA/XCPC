#include <bits/stdc++.h>
using namespace std;
int n;
string s,t;
void solve()
{
	cin>>n>>s;
	t="";
	if(s[0]=='0') t+='0';
	else t+='1';
	char p=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='0'&&p=='0') continue;
		t+=s[i];
		p=s[i];
	}
	if(count(t.begin(),t.end(),'1')>count(t.begin(),t.end(),'0')) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
