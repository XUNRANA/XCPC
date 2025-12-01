#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	
	int n=s.size();
	s=" "+s;
	
	int q,i,v;
	
	set<int>st;
	for(int i=1;i<=n;i++) if(i+3<=n&&s.substr(i,4)=="1100") st.insert(i);
	
	cin>>q;
	
	while(q--)
	{
		cin>>i>>v;
		if(s[i]==(v+'0')) 
		{
			if(st.size()) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		
		if(s[i]=='1')//1 2 
		{
			if(st.find(i)!=st.end()) st.erase(i);
			if(i-1>=1&&st.find(i-1)!=st.end()) st.erase(i-1);
		}
		else// 3 4
		{
			if(i-2>=1&&st.find(i-2)!=st.end()) st.erase(i-2);
			if(i-3>=1&&st.find(i-3)!=st.end()) st.erase(i-3);
		}
		
		
		s[i]=v+'0';
		for(int j=max(1,i-3);j<=i;j++)
		{
			if(j+3<=n&&s.substr(j,4)=="1100") st.insert(j);
		}
//		cout<<s<<"\n";
//		for(auto i:st) cout<<i<<"\n";
		if(st.size()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
