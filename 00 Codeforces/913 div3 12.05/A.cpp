#include <bits/stdc++.h>
using namespace std;
string s,t;
void solve()
{
	cin>>s;
	set<string>st;
	for(int i=1;i<=8;i++) 
	{
		t="";
		t+=s[0];
		t+='0'+i;
		st.insert(t);
		t="";
		t+='a'-1+i;
		t+=s[1];
		st.insert(t);
	}
	for(auto i:st) if(i!=s) cout<<i<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
