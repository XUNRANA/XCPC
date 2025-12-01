#include <bits/stdc++.h>
using namespace std;

int f1(string s)
{
	int val=1;
	int ans=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(isdigit(s[i])) ans=ans+val*(s[i]-'0');
		else ans=ans+val*(s[i]-'A'+10);
		val=val*27;
	}
	return ans;
}
string f2(int a)
{
	string ans="";
	while(a)
	{
		int t=a%27;
		// cout<<t<<"\n";
		if(t<=9) ans=char('0'+t)+ans;
		else ans=char('A'+t-10)+ans;
		a/=27;
	}
	return ans;
}
void solve()
{
	string a;
	int b;
	cin>>a>>b;
	if(b==27) cout<<f1(a);
	else cout<<f2(stoi(a));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
