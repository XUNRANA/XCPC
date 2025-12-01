#include <bits/stdc++.h>
using namespace std;
int n;
string s,t;
void solve()
{
	cin>>n>>s;
	t="";
	for(int i=s.size()-1;i>=0;i--) t+=s[i];
	if(s==t)
	{
		cout<<s<<"\n";
	}
	else if(s<t)
	{
		if(n&1) cout<<s<<" "<<t<<"\n";
		else cout<<s<<"\n";
	}
	else 
	{
		if(n&1) cout<<t<<"\n";
		else cout<<t<<s<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
