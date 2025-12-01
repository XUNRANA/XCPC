#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,q,l,r;
	string s;
	cin>>n>>q>>s;
	while(q--)
	{
		string t;
		cin>>l>>r;
		for(int i=0;i<l-1;i++) t+=s[i];
		for(int i=l-1;i<=r-1;i++) 
		{
			t+=s[i];
			t+=s[i]; 
		}
		for(int i=r;i<s.size();i++) t+=s[i];
		s=t;
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

