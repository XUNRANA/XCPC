#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,m;
	cin>>n;
	set<string>st;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==1) 
		{
			string s;
			cin>>s;
			continue;
		}
		while(x--)
		{
			string s;
			cin>>s;
			st.insert(s);
		}
	}
	cin>>m;
	set<string>st1;
	int f=0;
	while(m--)
	{
		string s;
		cin>>s;
		if(st.find(s)!=st.end()) continue;
		
		if(st1.find(s)==st1.end())
		{
			if(f) cout<<" "; 
			cout<<s;
			f=1;
			st1.insert(s);
		}
	}
	if(!f) cout<<"No one is handsome\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

