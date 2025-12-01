#include <bits/stdc++.h>
using namespace std;
string fx(string a,int b)
{
	reverse(a.begin(),a.end());
	string ans="";
	int c=2;
	for(auto i:a)
	{
		int s=(i-'0'+c);
		ans+=s%10+'0';
		c=s/10;
	}
	if(c) ans+='0'+c;
	reverse(ans.begin(),ans.end());
	return ans;
}
void solve()
{
	string s;
	cin>>s;
	if(s.size()&1) cout<<"Error: "<<s.size()<<" digit(s)\n";
	else
	{
		int n=s.size();
		string a=s.substr(0,n/2);
		string b=s.substr(n/2);
		if(fx(a,2)==b) cout<<"Yes: "<<b<<" - "<<a<<" = "<<2<<"\n";
		else cout<<"No: "<<b<<" - "<<a<<" != "<<2<<"\n";
	}
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
