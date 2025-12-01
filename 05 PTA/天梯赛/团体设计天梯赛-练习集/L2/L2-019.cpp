#include <bits/stdc++.h>
using namespace std;
int n,m;
string t;
string s[10010];
int a[10010];
void solve()
{
	set<string>st,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		st.insert(t);
	}
	cin>>m;
	int sum=0;
	for(int i=1;i<=m;i++) cin>>s[i]>>a[i],sum+=a[i];
	
	for(int i=1;i<=m;i++)
	{
		if(a[i]*m>sum)
		{
			if(!st.count(s[i])) ans.insert(s[i]);
		}
	}
	if(!ans.size()) cout<<"Bing Mei You\n";
	else for(auto i:ans) cout<<i<<"\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

