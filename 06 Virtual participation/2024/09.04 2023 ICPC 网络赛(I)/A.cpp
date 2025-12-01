#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	map<string,int>m1,m2;
	vector<string>a,b;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(m1.count(s)) continue;
		m1[s]=i;
		a.push_back(s);
	}
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		if(m2.count(s)) continue;
		m2[s]=i;
		b.push_back(s);
	}
	
	unordered_set<string>st;
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		if(!st.count(a[i]))
		{
			cout<<a[i]<<"\n";
			st.insert(a[i]);
		}
		if(!st.count(b[i]))
		{
			cout<<b[i]<<"\n";
			st.insert(b[i]);
		}
	}

	for(int i=min(a.size(),b.size());i<max(a.size(),b.size());i++)
	{
		if(a.size()>b.size()) 
		{
			if(!st.count(a[i]))
			{
				cout<<a[i]<<"\n";
				st.insert(a[i]);
			}
		}
		else 
		{
			if(!st.count(b[i]))
			{
				cout<<b[i]<<"\n";
				st.insert(b[i]);
			}
		}
 	}
 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
